Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.name    = "ScrapingKit"
  s.version = "0.0.1"
  s.summary = "ScrapingKit <(^_^;)"

  s.description  = <<-DESC
                   blah blah blah blah blah blah blah.
                   DESC

  s.homepage = "https://github.com/hisui/scrapingkit"

  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.license  = { :type => "MIT", :file => "LICENSE.txt" }

  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.author = { "shun" => "findall3@gmail.com" }

  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.platform = :ios, "5.0"
  
  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.source = { :git => "https://github.com/hisui/scrapingkit.git", :tag => "0.0.1" }

  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.source_files        = "ScrapingKit", "ScrapingKit/**/*.{h,hpp,c,cpp,m,mm}"
  s.public_header_files = "ScrapingKit/**/*.{h,hpp}"

  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  s.requires_arc = true

end
