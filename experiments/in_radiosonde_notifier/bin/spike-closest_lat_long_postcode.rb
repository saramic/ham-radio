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
  Math.acos(
    Math.sin(lat_a) * Math.sin(lat_b) +
    Math.cos(lat_a) * Math.cos(lat_b) *
    Math.cos(lon_b - lon_a)
  ) * 6371
end

my_lat_long = {latitude: ARGV[0].to_f, longitude: ARGV[1].to_f}

distances = []
lat_long.each do |lat_long_postcode|
  distances << {
    distance: distance.call(
      my_lat_long[:latitude],
      my_lat_long[:longitude],
      lat_long_postcode[:latitude],
      lat_long_postcode[:longitude]
    ),
    suburb: lat_long_postcode
  }
end
pp distances.min_by { |a| a[:distance] }
