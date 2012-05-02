# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "ewah-bitset"
  s.version = "0.0.3"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.2") if s.respond_to? :required_rubygems_version=
  s.authors = ["Josh Ferguson"]
  s.date = "2012-05-02"
  s.description = "A wrapper around Lemire's EWAHBoolArray from https://github.com/lemire/EWAHBoolArray"
  s.email = "josh@besquared.net"
  s.extensions = ["ext/extconf.rb"]
  s.extra_rdoc_files = ["CHANGELOG", "LICENSE", "README.md", "ext/boolarray.h", "ext/ewah-bitset.cpp", "ext/ewah.h", "ext/extconf.rb"]
  s.files = ["CHANGELOG", "LICENSE", "Manifest", "README.md", "Rakefile", "ext/boolarray.h", "ext/ewah-bitset.cpp", "ext/ewah.h", "ext/extconf.rb", "spec/ewah_bitset_spec.rb", "spec/spec.opts", "ewah-bitset.gemspec"]
  s.homepage = "http://www.github.com/yammer/ewah-bitset/"
  s.rdoc_options = ["--line-numbers", "--inline-source", "--title", "Ewah-bitset", "--main", "README.md"]
  s.require_paths = ["lib", "ext"]
  s.rubyforge_project = "ewah-bitset"
  s.rubygems_version = "1.8.15"
  s.summary = "A wrapper around Lemire's EWAHBoolArray from https://github.com/lemire/EWAHBoolArray"

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
