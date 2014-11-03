Pod::Spec.new do |s|
  s.name         = "OpenSSL-gabriel"
  s.version      = "1.0.1.j"
  s.summary      = "OpenSSL"
  s.description  = "OpenSSL"
  s.homepage     = ""
  s.license      = { :type => "MIT" }
  s.source       = { :git => "https://github.com/gabriel/OpenSSL-gabriel.git", :tag => "#{s.version}" }

  s.authors       =  {}
  
  s.ios.platform          = :ios, "8.0"
  s.ios.deployment_target = "8.0"
  s.ios.source_files        = "include/openssl/**/*.h"
  s.ios.public_header_files = "include/openssl/**/*.h"
  s.ios.header_dir          = "openssl"
  s.ios.preserve_paths      = "lib/libcrypto.a", "lib/libssl.a"
  s.ios.vendored_libraries  = "lib/libcrypto.a", "lib/libssl.a"
  
  s.libraries = "ssl", "crypto"

end
