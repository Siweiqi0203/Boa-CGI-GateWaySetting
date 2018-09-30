/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-27 16:03:45 
 * @Last Modified by:   Weiqi Si 
 * @Last Modified time: 2018-09-27 16:03:45 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(int argc, char *argv[])
{
	/* CGI标准 */

	printf("Content-type:text/html;charset=utf-8\n\n");
	printf("\n");

	//HTML
	printf("<html><head>");
	printf("<title>ADD_DEVICE_CONFIG</title>");
	
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap.css' />");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap-select.css' />");
	printf("<script src='/bootstrap/js/jquery-1.11.1.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap-select.js'></script>");
	printf("<script language=\"JavaScript\" src=\"/bootstrap/js/deviceDEL.js\"></script>");
	printf("</head><body>");

	//Bootstrap下界面
	printf("<div class='container'>");
	printf("<div class='row'>");
	printf("<div class='col-sm-8 col-sm-offset-2'>");
	printf("<div class='page-header'>");
	printf("<div class='alert alert-info' role='alert'>");
	printf("<h4>Please delete device in this CGI page.</h4></div></div>");

	printf("<div class='panel panel-default'><div class='panel-heading'><h3 class='panel-title'>Device Form</h3></div>");
	printf("<div class='panel-body'>");
	printf("<form action='/cgi-bin/jsondel.cgi' method='post' class='form-horizontal'>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='name'>Name</label><div class='col-sm-5'><select name='name' id='name' class='selectpicker'></select></div></div>");
	printf("<div class='form-group'><div class='col-sm-9 col-sm-offset-4'><button type='submit' class='btn btn-warning' value='del'>Delete</button></div></div>");
	printf("</form></div></div>");
	printf("</div></div></div></body></html>");
	return 0;


}
