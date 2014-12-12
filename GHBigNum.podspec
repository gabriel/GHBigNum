Pod::Spec.new do |s|

  s.name         = "GHBigNum"
  s.version      = "0.1.4"
  s.summary      = "BigNum library (from OpenSSL)"
  s.homepage     = "https://github.com/gabriel/GHBigNum"
  s.license      = { :type => "MIT" }
  s.author       = { "Gabriel Handford" => "gabrielh@gmail.com" }
  s.source       = { :git => "https://github.com/gabriel/GHBigNum.git", :tag => s.version.to_s }
  s.dependency "OpenSSL-gabriel", "~> 1.0.1.j-2"
  s.source_files = "GHBigNum/**/*.{c,h,m}"
  s.requires_arc = true
  s.ios.platform = :ios, "8.0"
  s.ios.deployment_target = "8.0"

  s.osx.platform = :osx, "10.9"
  s.osx.deployment_target = "10.9"

end
