require 'echoe'
require 'rake'
require 'rspec/core/rake_task'

task :default => :spec

Echoe.new("ewah-bitset") do |p|
  p.author = "Josh Ferguson"
  p.email = "josh@besquared.net"
  p.project = "ewah-bitset"
  p.summary = "A wrapper around Lemire's EWAHBoolArray from https://github.com/lemire/EWAHBoolArray"
  p.url = "http://www.github.com/yammer/ewah-bitset/"
end

RSpec::Core::RakeTask.new(:spec) do |t|
  t.pattern = 'spec/**/*_spec.rb'
  t.rspec_opts = ['--options', "\"spec/spec.opts\""]
end