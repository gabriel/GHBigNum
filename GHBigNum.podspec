Pod::Spec.new do |s|

  s.name         = "GHBigNum"
  s.version      = "0.1.1"
  s.summary      = "BigNum library (from OpenSSL)"
  s.homepage     = "https://github.com/gabriel/GHBigNum"
  s.license      = { :type => "MIT" }
  s.author       = { "Gabriel Handford" => "gabrielh@gmail.com" }
  s.source       = { :git => "https://github.com/gabriel/GHBigNum.git", :tag => s.version.to_s }
  s.dependency 'OpenSSL-Universal'
  s.source_files = 'GHBigNum/**/*.{c,h,m}'
  s.requires_arc = true

end
