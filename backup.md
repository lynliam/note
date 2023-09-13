```xml
 <!-- 英文默认字体 -->
  <match>
    <!-- 默认衬线字体 -->
    <test qual="any" name="family">
      <string>serif</string>
    </test>
    <edit name="family" mode="prepend" binding="strong">
      <string></string>
    </edit>
  </match>
  <match target="pattern">
  <!-- 默认无衬线字体 -->
    <test qual="any" name="family">
      <string>sans-serif</string>
    </test>
    <edit name="family" mode="prepend" binding="strong">
      <string>Source Sans Pro</string>
    </edit>
  </match>
  <match target="pattern">
  <!-- 默认等宽字体 -->
    <test qual="any" name="family">
      <string>monospace</string>
    </test>
    <edit name="family" mode="prepend" binding="strong">
      <string>Source Code Pro</string>
    </edit>
  </match>

  <!-- 中文默认字体 -->
  <match>
    <!-- 默认衬线字体 -->
    <test name="lang" compare="contains">
      <string>zh</string>
    </test>
    <test name="family">
      <string>serif</string>
    </test>
    <edit name="family" mode="prepend">
      <string>Source Han Serif CN</string>
    </edit>
  </match>
  <match>
    <!-- 默认无衬线字体 -->
    <test name="lang" compare="contains">
      <string>zh</string>
    </test>
    <test name="family">
      <string>sans-serif</string>
    </test>
    <edit name="family" mode="prepend">
      <string>Source Han Sans C</string>
    </edit>
  </match>
  <match>
    <!-- 默认等宽字体 -->
    <test name="lang" compare="contains">
      <string>zh</string>
    </test>
    <test name="family">
      <string>monospace</string>
    </test>
    <edit name="family" mode="prepend">
      <string>Source Han Mono SC</string>
    </edit>
  </match>

```

