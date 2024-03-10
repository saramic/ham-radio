#!/usr/bin/env ruby

require "csv"
require "JSON"

lat_long = CSV.read(
  File.join(File.dirname(__FILE__), "../data/australian-postcodes.csv"),
  headers: true
)

lat_long.map do |line|
  line["longitude"] = line["longitude"].to_f
  line["latitude"] = line["latitude"].to_f
end

distance = lambda do |lat_a, lon_a, lat_b, lon_b|
  Math.acos(
    Math.sin(lat_a) * Math.sin(lat_b) +
    Math.cos(lat_a) * Math.cos(lat_b) *
    Math.cos(lon_b - lon_a)
  ) * 6371
end

# Melbourne airport
my_lat_long = {latitude: -37.6697, longitude: 144.831}

distances = []
lat_long.each do |lat_long_postcode|
  distances << {distance: distance.call(
    my_lat_long[:latitude],
    my_lat_long[:longitude],
    lat_long_postcode["latitude"],
    lat_long_postcode["longitude"]
  ), suburb: lat_long_postcode}
end
pp distances.min_by { |a| a[:distance] }

# Mount Evelyn
my_lat_long = {latitude: -37.7767, longitude: 145.428}
distances = []
lat_long.each do |lat_long_postcode|
  distances << {distance: distance.call(
    my_lat_long[:latitude],
    my_lat_long[:longitude],
    lat_long_postcode["latitude"],
    lat_long_postcode["longitude"]
  ), suburb: lat_long_postcode}
end
pp distances.min_by { |a| a[:distance] }
