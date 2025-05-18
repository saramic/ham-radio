#!/usr/bin/env ruby
# rubocop:disable Layout/LeadingCommentSpace
#MISE description="download"
# rubocop:enable Layout/LeadingCommentSpace

require "fileutils"
require "open-uri"
# install nokogiri if it is not available
unless system("gem list nokogiri -i --silent")
  puts "Installing Nokogiri ..."
  system("gem install nokogiri")
end
require "nokogiri"

dirname = "data"
unless File.directory?(dirname)
  FileUtils.mkdir_p(dirname)
end

# root page
base_uri = "https://hardwarecomputerist.atariverse.com"
doc = Nokogiri::HTML(URI.open(base_uri))
hardware_link = doc.css("a").find{|e| e["class"] == "Hardware" }["href"]
base = doc.css("head base").first["href"]
hardware_link = URI.join(base_uri, base, hardware_link)

# hardware overview page
doc = Nokogiri::HTML(URI.open(hardware_link))
resource_general_link = doc
  .css(".Navigation")
  .find{|e| e.text =~ /Resource/ }.css("a")
  .find{|e| e.text =~ /General/ }["href"]
resource_general_link = URI.join(base_uri, base, resource_general_link)

# resource page
doc = Nokogiri::HTML(URI.open(resource_general_link))
base = doc.css("head base").first["href"]
pdf_links = doc
  .css("a")
  .find_all{|e| e["href"] =~ /Encyclopedia of Electronic Circuits/ }
  .map{|e| e["href"] }
pdf_links.each do |pdf_link|
  pdf_link = URI::DEFAULT_PARSER.escape(pdf_link)
  pdf_link = URI.join(base_uri, base, pdf_link)
  `wget #{pdf_link} --directory-prefix=#{dirname} --no-clobber`
end
