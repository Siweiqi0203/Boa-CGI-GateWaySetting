# Boa-CGI-GateWaySetting

Made by Weiqi Si.
在Tinker网关平台下，内建Boa服务，可以通过Browser访问ip，通过CGI网页对网关进行配置修改。

## Linux/Boa 服务搭建

1.[下载boa](http://www.boa.org/) 并解压<br>
2.在解压后的src目录下，执行./configure生成makefile<br>
3.执行make（可能会出现很多编译错误，自行百度）<br>
4.将boa拷贝到目标板的/bin目录下，同时把boa.conf，放入etc/boa下<br>
5.配置boa.conf <br>
User（48行）默认nobody，改为root<br>
Group（49行）默认nogroup，改为root<br>
ErrorLog（62行）默认/var/log/boa/error_log，需要手动建立/var/log/boa目录<br>
AccessLog（74行）默认/var/log/boa/access_log，需要手动建立/var/log/boa目录<br>
ServerName（94行） www.your.org.here前注解#去掉 <br>
DocumentRoot(111行）默认/var/www，需手动建立目录<br>
DirectoryIndex（123行）默认index.html<br>
ScriptAlias（193行）默认/cgi-bin/ /usr/lib/cgi-bin/，需手动建立目录，习惯修改至/var/www/cgi-bin<br>
	
## CGI编译

在/var/www/cgi-bin下，将固定格式的C file 编译，将执行文件后缀改为cgi即可，如deviceDEL.cgi

## Todo

Bootstrap框架下，已有device信息编辑界面修改未完成。




