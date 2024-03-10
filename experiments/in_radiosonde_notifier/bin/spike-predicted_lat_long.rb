#!/usr/bin/env ruby

# bin/spike-closest_lat_long_postcode.rb -37.68803 144.83568

require "csv"
require "open-uri"
require "net/http"

prediction_url = URI.parse("https://api.v2.sondehub.org/tawhiri")
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

# fetch and parse as CSV
response = Net::HTTP.get_response(prediction_url)
prediction_data = CSV.parse(
  response.body,
  headers: true,
  header_converters: :symbol
)

# output the destination
puts prediction_data[prediction_data.length - 1].to_h.slice(:latitude, :longitude).values.join(" ")
