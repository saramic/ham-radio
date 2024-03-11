#!/usr/bin/env ruby

require "csv"
require "JSON"

float_converter = lambda do |line|
  /\d+\.\d+/.match?(line) ? line.to_f : line
end

lat_long = CSV.read(
  File.join(File.dirname(__FILE__), "../data/australian-postcodes.csv"),
  headers: true,
  header_converters: :symbol,
  converters: float_converter
)

distance = lambda do |lat_a, lon_a, lat_b, lon_b|
  lat_a_rad = lat_a * Math::PI / 180
  lon_a_rad = lon_a * Math::PI / 180
  lat_b_rad = lat_b * Math::PI / 180
  lon_b_rad = lon_b * Math::PI / 180
  Math.acos(
    Math.sin(lat_a_rad) * Math.sin(lat_b_rad) +
    Math.cos(lat_a_rad) * Math.cos(lat_b_rad) *
    Math.cos(lon_b_rad - lon_a_rad)
  ) * 6371
end

my_lat_long = {latitude: ARGV[0].to_f, longitude: ARGV[1].to_f}
closest_postcode = lat_long.min do |a_lat_long_postcode, b_lat_long_postcode|
  distance.call(
    my_lat_long[:latitude],
    my_lat_long[:longitude],
    a_lat_long_postcode[:latitude],
    a_lat_long_postcode[:longitude]
  ) <=> distance.call(
    my_lat_long[:latitude],
    my_lat_long[:longitude],
    b_lat_long_postcode[:latitude],
    b_lat_long_postcode[:longitude]
  )
end
pp closest_postcode
pp distance.call(
  my_lat_long[:latitude],
  my_lat_long[:longitude],
  closest_postcode[:latitude],
  closest_postcode[:longitude]
)
