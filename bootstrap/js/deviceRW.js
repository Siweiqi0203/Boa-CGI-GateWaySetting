/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-30 10:05:16 
 * @Last Modified by: Weiqi Si
 * @Last Modified time: 2018-09-30 14:10:16
 */

// JavaScript source code
$(function () 
{
    $("#edit_button").click(function () 
    {
        $("#deviceform").submit();    //提交ID为myform的表单
    })
    $("#refresh").click(function () 
    {
        $("#deviceform").submit();    //提交ID为myform的表单
    })
    var data = [];
    $.ajax(
        {
        type: "get",
        url: "/data/test.json",
        dataType: "json",
        success: function (result) 
        {
            $("#lang").val(result.lang);
            $("#cuid").val(result.cuid);
            $("#screenPath").val(result.screenPath);
            //addBox(result);            
            $.each(result.devices, function (i, obj) 
            {
                data.push(obj);
            });
            $('#device_table').bootstrapTable(
                {
                data: data,
                url: '/data/test.json',         //请求后台的URL（*）
                method: 'get',                      //请求方式（*）
                //toolbar: '#toolbar',                //工具按钮用哪个容器
                striped: false,                      //是否显示行间隔色
                bordered: false,
                cache: false,                       //是否使用缓存，默认为true，所以一般情况下需要设置一下这个属性（*）
                pagination: true,                   //是否显示分页（*）
                sortable: false,                     //是否启用排序
                sortOrder: "asc",                   //排序方式
                //queryParams: oTableInit.queryParams,//传递参数（*）
                sidePagination: "server",           //分页方式：client客户端分页，server服务端分页（*）
                pageNumber: 1,                       //初始化加载第一页，默认第一页
                pageSize: 10,                       //每页的记录行数（*）
                pageList: [10, 25, 50, 100],        //可供选择的每页的行数（*）
                search: false,                       //是否显示表格搜索，此搜索是客户端搜索，不会进服务端，所以，个人感觉意义不大
                strictSearch: false,
                showColumns: false,                  //是否显示所有的列
                showRefresh: true,                  //是否显示刷新按钮
                //minimumCountColumns: 5,             //最少允许的列数
                clickToSelect: true,                //是否启用点击选中行
                //height: $(window).height() - 280,                        //行高，如果没有设置height属性，表格自动根据记录条数觉得表格高度
                uniqueId: "ID",                     //每一行的唯一标识，一般为主键列
                showToggle: false,                    //是否显示详细视图和列表视图的切换按钮
                cardView: false,                    //是否显示详细视图
                detailView: false,                   //是否显示父子表
                columns: [
                    {
                        field: 'name',
                        title: 'name',
                    }, {
                        field: 'enabled',
                        title: 'enabled',
                    }, {
                        field: 'connMode',
                        title: 'connMode',
                    }, {
                        field: 'connType',
                        title: 'connType',
                    }, {
                        field: 'deviceId',
                        title: 'deviceId',
                    }, {
                        field: 'factoryId',
                        title: 'factoryId',
                    }, {
                        field: 'versionId',
                        title: 'versionId',
                    }, {
                        field: 'address',
                        title: 'address',
                    }, {
                        field: 'port',
                        title: 'port',
                    }, {
                        field: 'timeout',
                        title: 'timeout',
                    }, {
                        field: 'deviceKey',
                        title: 'deviceKey',
                    },
                ]
            });            
        }
    });

    

    
});




function addBox(result) 
{
    $("#lang").val(result.lang);

    $("#cuid").val(result.cuid);

    $("#screenPath").val(result.screenPath);

    $.each(result.devices, function (i, obj) 
    {
        //jquery读取，以json格式添加表
        $("#deviceRW").append(
            "<table border=\"1\" cellspacing=\"0\" cellpadding=\"5\" align='center'><tbody>" +
            //设备号
            "<tr><td class='title' colspan='2' align='center'>devices" + i + "</td></tr>" +
            //
            "<tr><td>name</td>" + "<td><input name='name' value='" + obj['name']+"'></td></tr>" +
            //
            "<tr><td>enabled</td>" +"<td><select name='enabled' id='enabled"+i+"'></select></td></tr>" +
            //
            "<tr><td>connMode</td>" + "<td><select name='connMode' id='connMode"+i+"'></select></td></tr>"+
            //
            "<tr><td>connType</td>" + "<td><select name='connType' id='connType"+i+"'></select></td></tr>" +
            //
            "<tr><td>deviceId</td>" + "<td><select name='deviceId' id='deviceId"+i+"'></select></td></tr>" +
            //
            "<tr><td>factoryId</td>" + "<td><select name='factoryId' id='factoryId"+i+"'></select></td></tr>" +
            //
            "<tr><td>versionId</td>" + "<td><select name='versionId' id='versionId" + i +"'><option value='1'>V1</option></select></td></tr>" +
            //
            "<tr><td>address</td>" + "<td><input name='address' value='" + obj['address'] + "'></td></tr>" +
            //
            "<tr><td>port</td>" + "<td><input name='port' value='" + obj['port'] + "'></td></tr>" +
            //
            "<tr><td>timeout</td>" + "<td><input name='timeout' value='" + obj['timeout'] + "'></td></tr>" +
            //
            "<tr><td>deviceKey</td>" + "<td><select name='deviceKey' id='deviceKey" + i +"'><option value='null'>NULL</option></select></td></tr></tbody></table>"
        );

        //选中返回值
        var enabled = document.getElementById("enabled" + i);
        jsAddItemToSelect(enabled, "FALSE", "false");
        jsAddItemToSelect(enabled, "TRUE", "true");
        var str = JSON.stringify(obj['enabled']);
        jsSelectItemByValue(enabled, str);

        var connMode = document.getElementById("connMode" + i);
        jsAddItemToSelect(connMode, "LOCAL_TO_REMOTE_CLIENT", "1");
        jsAddItemToSelect(connMode, "REMOTE_TO_LOCAL_CLIENT", "2");
        jsAddItemToSelect(connMode, "LOCAL_SERVER", "3");
        str = JSON.stringify(obj['connMode']);
        jsSelectItemByValue(connMode, str);

        var connType = document.getElementById("connType" + i);
        jsAddItemToSelect(connType, "TCP_IP_MODE", "1");
        jsAddItemToSelect(connType, "UDP_MODE", "2");
        jsAddItemToSelect(connType, "SERIAL_MODE", "3");
        jsAddItemToSelect(connType, "HTTP_MODE", "4");
        str = JSON.stringify(obj['connType']);
        jsSelectItemByValue(connType, str);

        var deviceId = document.getElementById("deviceId" + i);
        jsAddItemToSelect(deviceId, "CHARGING", "1");
        jsAddItemToSelect(deviceId, "SCREEN", "2");
        jsAddItemToSelect(deviceId, "SENSOR", "3");
        jsAddItemToSelect(deviceId, "NBIOT", "4");
        jsAddItemToSelect(deviceId, "LIGHTINGSHOW", "5");
        str = JSON.stringify(obj['deviceId']);
        jsSelectItemByValue(deviceId, str);

        var factoryId = document.getElementById("factoryId" + i);
        if (deviceId.value == "1") {
            jsAddItemToSelect(factoryId, "WANMA", "1");
            jsAddItemToSelect(factoryId, "NANRUI", "2");
            jsAddItemToSelect(factoryId, "JUDIAN", "3");
        }
        if (deviceId.value == "2") {
            jsAddItemToSelect(factoryId, "SCCS", "1");
        }
        if (deviceId.value == "3") {
            jsAddItemToSelect(factoryId, "HONGSUI", "1");
            jsAddItemToSelect(factoryId, "XINPUHUI", "2");
            jsAddItemToSelect(factoryId, "FRT", "3");
            jsAddItemToSelect(factoryId, "ZHIXIANG", "4");
        }
        if (deviceId.value == "4") {
            jsAddItemToSelect(factoryId, "LORAWAN", "1");
        }
        if (deviceId.value == "5") {
            jsAddItemToSelect(factoryId, "EXC", "1");
        }
        str = JSON.stringify(obj['factoryId']);
        jsSelectItemByValue(factoryId, str);

    });
}

// 1.判断select选项中 是否存在Value="paraValue"的Item        
function jsSelectIsExitItem(objSelect, objItemValue) 
{
    var isExit = false;
    for (var i = 0; i < objSelect.options.length; i++) 
    {
        if (objSelect.options[i].value == objItemValue) 
        {
            isExit = true;
            break;
        }
    }
    return isExit;
}

// 2.向select选项中 加入一个Item        
function jsAddItemToSelect(objSelect, objItemText, objItemValue) 
{
    //判断是否存在        
    if (jsSelectIsExitItem(objSelect, objItemValue)) 
    {
        //alert("该Item的Value值已经存在");
    } else {
        var varItem = new Option(objItemText, objItemValue);
        objSelect.options.add(varItem);
        //alert("成功加入");
    }
}

// 3.从select选项中 删除Item        
function jsRemoveItemFromSelect(objSelect) 
{
    //判断是否存在  
    var len = objSelect.options.length;
    for (var i = len - 1; i >= 0; i--) 
    {
        if (objSelect.options[i].value != null) 
        {
            objSelect.options.remove(i);

        }
    }
}


// 4.删除select中选中的项    
function jsRemoveSelectedItemFromSelect(objSelect) 
{
    var length = objSelect.options.length - 1;
    for (var i = length; i >= 0; i--) 
    {
        if (objSelect[i].selected == true) 
        {
            objSelect.options[i] = null;
        }
    }
}

// 5.修改select选项中 value="paraValue"的text为"paraText"        
function jsUpdateItemToSelect(objSelect, objItemText, objItemValue)
{
    //判断是否存在        
    if (jsSelectIsExitItem(objSelect, objItemValue)) 
    {
        for (var i = 0; i < objSelect.options.length; i++) 
        {
            if (objSelect.options[i].value == objItemValue) 
            {
                objSelect.options[i].text = objItemText;
                break;
            }
        }
    }
}

// 6.设置select中text="paraText"的第一个Item为选中        
function jsSelectItemByValue(objSelect, objItemValue) 
{
    //判断是否存在        
    var isExit = false;
    for (var i = 0; i < objSelect.options.length; i++) 
    {
        if (objSelect.options[i].value == objItemValue) 
        {
            objSelect.options[i].selected = true;
            isExit = true;
            break;
        }
    }
}
