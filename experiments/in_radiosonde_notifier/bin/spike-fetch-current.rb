#!/usr/bin/env ruby

# bin/spike-fetch-current.rb "Melbourne (AU)"

require "selenium-webdriver"
require "open-uri" # needed for iso8601 below

location_list_url = URI.parse("https://s1.radiosondy.info/sonde_table.php")
params = {
  startplace: ARGV[0],
  table: "startplace"
}
location_list_url.query = URI.encode_www_form(params)

driver = Selenium::WebDriver.for :chrome
driver.navigate.to location_list_url
# driver.manage.window.resize_to(960, 750)
# wait = Selenium::WebDriver::Wait.new
#
# wait.until do
#   driver.find_elements(class: "leaflet-marker-icon").count == 3 # launch 🎈, pop 💥, land 🛬
# end

rows = driver.find_elements(css: "#list_container tr")
headers = rows[0]
  .find_elements(css: "th")
  .map { |header| header.text.downcase.to_sym }
# NOTE: there are over 3,500 nodes which take way too long to process all of
#       them in this fashion
last_10 = rows
  .slice(1, 10)
  .map { |row|
    headers.zip(
      row.find_elements(css: "td")
      .map(&:text)
    ).to_h.merge(
      link: row.find_elements(css: "a").first["href"]
    )
  }
current = last_10.first

driver.navigate.to current[:link]

wait = Selenium::WebDriver::Wait.new

wait.until do
  # 5: launch 🚀, balloon 🎈, home 🏠, burst 💥, land 🛬
  driver.find_elements(class: "leaflet-marker-icon").count >= 4 # home 🏠 - not guaranteed
end

driver.save_screenshot("tmp/progress_#{current[:number]}.png")
puts current[:link]
puts `~/.iterm2/imgcat tmp/progress_#{current[:number]}.png`
