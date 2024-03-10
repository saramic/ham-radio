#!/usr/bin/env ruby

# bin/makefile/fetch-gist.rb https://gist.github.com/randomecho/5020859

require "open-uri"

# fetch the gist HTML
url = URI.parse(ARGV[0])
gist_content = url.open

# extract the raw url and fetch
matches = /(<a href="#{url.path.tr("/", "/")}\/raw\/[^>]*>)/.match(gist_content.read)
url.path = matches[1][/href="([^"]*)"/, 1]
raw_content = url.open

# output
$stdout.puts raw_content.read
