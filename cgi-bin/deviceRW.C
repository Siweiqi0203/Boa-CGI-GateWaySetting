/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-27 16:03:26 
 * @Last Modified by:   Weiqi Si 
 * @Last Modified time: 2018-09-27 16:03:26 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(int argc,char *argv[])
{
	/* CGI标准 */

 	printf("Content-type:text/html;charset=utf-8\n\n\n");

	// HTML
	printf("<html><head>");
	printf("<title>READ_GATEWAY_CONFIG</title>");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap.css' />");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap-select.css' />");
	printf("<link rel='stylesheet' href='/bootstrap/css/bootstrap-table.min.css' />");

	printf("<script src='/bootstrap/js/jquery-1.11.1.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap-select.js'></script>");
	printf("<script src='/bootstrap/js/bootstrap-table.min.js'></script>");

	printf("<script src='/bootstrap/js/jquery.validate.js'></script>");
	printf("<script language=\"JavaScript\" src=\"/bootstrap/js/deviceRW.js\"></script>");
	printf("</head><body>");
	
	// Bootstrap下界面
	printf("<div class='container'>");
	printf("<div class='row'>");
	printf("<div class='col-sm-8 col-sm-offset-2'>");
	printf("<div class='page-header'>");
	printf("<div class='alert alert-info' role='alert'>");
	printf("<h4>Please add edit device in this CGI page.Note:1.All device settings can not be empty.2.Please do not enter Chinese characters, which may make file scramble.</h4></div></div>");

	printf("<div class='panel panel-default'><div class='panel-heading'><h3 class='panel-title'>Device Info</h3></div>");
	printf("<div class='panel-body'>");
	printf("<br><br><form action='/cgi-bin/jsonheadrw.cgi' method='post' id='deviceform' class='form-horizontal'>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='lang'>Lang</label><div class='col-sm-5'><input type='text' name='lang' id='lang' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='cuid'>Cuid</label><div class='col-sm-5'><input type='text' name='cuid' id='cuid' class='form-control'/></div></div>");
	printf("<div class='form-group'><label class='col-sm-4 control-label' for='screenPath'>ScreenPath</label><div class='col-sm-5'><input type='text' name='screenPath' id='screenPath' class='form-control'/></div></div>");
	printf("<div class='form-group'><div class='col-sm-9 col-sm-offset-4'><button class='btn btn-info' id='edit_button' >SAVE_EDIT</button></div></div></div>");
	printf("</form></div>");

	printf("<div class='panel panel-default'><div class='panel-heading'><h3 class='panel-title'>Device Form</h3></div>");
	printf("<div class='panel-body'>");

	printf("<a href=\"deviceADD.cgi\"><button class='btn btn-success btn-sm'>ADD_DEVICE</button></a><a href=\"deviceDEL.cgi\"><button class='btn btn-warning btn-sm'>DELETE_DEVICE</button></a></div></div>");
	printf("<table id='device_table' class='table table-hover' style='font-size:13px'></table>");

	printf("</div></div></div></body></html>");
	return 0;
		
}
