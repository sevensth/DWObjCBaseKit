Pod::Spec.new do |s|
  s.name         = 'DWObjCBaseKit'
  s.version      = '0.0.1'
  s.license      = 'Apache License, Version 2.0'
  s.summary      = 'Base methods and type defininations'
  s.homepage     = 'https://github.com/sevensth/DWObjCBaseKit'
  s.author       = { 'Sven Song' => 'shrimpeter@gmail.com' }
  s.source       = { :git => 'https://github.com/sevensth/DWObjCBaseKit.git', :tag => s.version.to_s }
  s.description  = 'This library provides a collection of base methods and type defininations.'
  s.ios.deployment_target = '8.0'
  s.requires_arc = true
  s.source_files  = 'Source', 'DWObjCBaseKit/Source/**/*.{h,m}'
  s.public_header_files = 'DWObjCBaseKit/Source/Public/**/*.h'
end
