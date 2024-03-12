#!/usr/bin/env ruby

# bin/spike-fetch-screenshot.rb

require "selenium-webdriver"
require "open-uri" # needed for iso8601 below

prediction_url = URI.parse("https://predict.sondehub.org/")
params = {
  profile: "standard_profile",
  pred_type: "single",
  launch_altitude: 0,
  launch_latitude: ARGV[0].to_f,
  launch_longitude: ARGV[1].to_f,
  launch_datetime: DateTime.now.to_time.utc.iso8601,
  ascent_rate: 5,
  burst_altitude: 30000,
  descent_rate: 5,
  format: "csv"
}
prediction_url.query = URI.encode_www_form(params)

driver = Selenium::WebDriver.for :chrome
driver.navigate.to prediction_url
driver.manage.window.resize_to(960, 750)
wait = Selenium::WebDriver::Wait.new
wait.until do
  driver.find_elements(class: "leaflet-marker-icon").count == 3 # launch 🎈, pop 💥, land 🛬
end

# this wait does not seem to work
wait.until do
  driver.find_elements(css: "img[src=\"images/target-1-sm.png\"]")
  driver.find_elements(css: "img[src=\"images/target-8-sm.png\"]")
end
sleep 0.4 # time to render all the icons

fingerprint = params.slice(:launch_latitude, :launch_longitude, :launch_datetime).values.join("_").tr(" ", "-")
driver.save_screenshot("tmp/predict_#{fingerprint}.png")
puts prediction_url
puts `~/.iterm2/imgcat tmp/predict_#{fingerprint}.png`
