Pod::Spec.new do |s|

  s.name         = "GHBigNum"
  s.version      = "0.1.6"
  s.summary      = "BigNum library (from OpenSSL)"
  s.homepage     = "https://github.com/gabriel/GHBigNum"
  s.license      = { :type => "MIT" }
  s.author       = { "Gabriel Handford" => "gabrielh@gmail.com" }
  s.source       = { :git => "https://github.com/gabriel/GHBigNum.git", :tag => s.version.to_s }
  s.dependency "OpenSSL-Universal", "~> 1.0.1k"
  s.source_files = "GHBigNum/**/*.{c,h,m}"
  s.requires_arc = true
  s.ios.platform = :ios, "7.0"
  s.ios.deployment_target = "7.0"

  s.osx.platform = :osx, "10.8"
  s.osx.deployment_target = "10.8"

end
