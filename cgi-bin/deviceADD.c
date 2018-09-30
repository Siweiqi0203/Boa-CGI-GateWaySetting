/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-27 16:03:57 
 * @Last Modified by: Weiqi Si
 * @Last Modified time: 2018-09-27 16:10:18
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(int argc, char *argv[])
{
	/* CGI标准 */

	printf("Content-type:text/html;charset=utf-8\n\n");//standard response header
	printf("\n");

	//HTML
	printf("<html><head>");
	printf("<title>ADD_DEVICE_CONFIG</title>");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap.css' />");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap-select.css' />");
	
	printf("<script src='/bootstrap/js/jquery-1.11.1.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap-select.js'></script>");
	printf("<script src='/bootstrap/js/defaults-zh_CN.js'></script>");
	printf("<script src='/bootstrap/js/jquery.validate.js'></script>");
	printf("<script src='/bootstrap/js/deviceADD.js'></script>");

	printf("</head><body>");

	// Bootstrap下界面
	printf("<div class='container'>");
	printf("<div class='row'>");
	printf("<div class='col-sm-8 col-sm-offset-2'>");
	printf("<div class='page-header'>");
	printf("<div class='alert alert-info' role='alert'>");
	printf("<h4>Please add new device in this CGI page.Note:1.All device settings can not be empty.2.Please do not enter Chinese characters, which may make file scramble.</h4></div></div>");
	printf("<div class='panel panel-default'><div class='panel-heading'><h3 class='panel-title'>Device Form</h3></div>");
	printf("<div class='panel-body'>");

	printf("<form action='/cgi-bin/jsonadd.cgi' method='post' id='deviceform' class='form-horizontal'>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='name'>Name</label><div class='col-sm-5'><input type='text' name='name' id='name' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='enabled'>Enabled</label><div class='col-sm-5'><select name='enabled' id='enabled' class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='connMode'>ConnMode</label><div class='col-sm-5'><select name='connMode' id='connMode'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='connType'>ConnType</label><div class='col-sm-5'><select name='connType' id='connType'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='deviceId'>DeviceId</label><div class='col-sm-5'><select name='deviceId' id='deviceId' onchange='deviceIdchange(this.value)'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='factoryId'>FactoryId</label><div class='col-sm-5'><select name='factoryId' id='factoryId'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='versionId'>VersionId</label><div class='col-sm-5'><select name='versionId' id='versionId'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='address'>Address</label><div class='col-sm-5'><input type='text' name='address' id='address' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='port'>Port</label><div class='col-sm-5'><input type='text' name='port' id='port' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='timeout'>Timeout</label><div class='col-sm-5'><input type='text' name='timeout' id='timeout' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='deviceKey'>deviceKey</label><div class='col-sm-5'><select name='deviceKey' id='deviceKey'class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><div class='col-sm-9 col-sm-offset-4'><button type='submit' class='btn btn-primary' value='add'>ADD</button></div></div>");
	printf("</form></div></div>");
	printf("</div></div></div></body></html>");
	return 0;


}
