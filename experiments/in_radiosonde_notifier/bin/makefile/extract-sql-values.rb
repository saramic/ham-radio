#!/usr/bin/env ruby

# cat IMPORT_FILE.sql | bin/makefile/extract-sql-values.rb

require "CSV"
in_data = false

strip_quotes = lambda do |line|
  line.strip
  line.gsub!(/^\s*'/, "")
  line.gsub!(/'$/, "")
  line
end

while (line = gets)
  case line
  when /INSERT/
    in_data = true
  end

  if in_data
    csv_line = line[/^\((.*)\)[,;]?\n$/, 1]
    csv_line ||= line[/^INSERT.*\(([^\)]*)\)/, 1]
    out = CSV.parse(csv_line, converters: strip_quotes).first.map do |line|
      /\d+\.\d+/.match?(line) ? line.to_f : line
    end
    puts out.to_csv
  end
end
