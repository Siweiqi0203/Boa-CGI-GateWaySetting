/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-27 17:13:19 
 * @Last Modified by: Weiqi Si
 * @Last Modified time: 2018-09-30 14:48:55
 */

$(function () 
{
    var enabled = document.getElementById("enabled");
    jsAddItemToSelect(enabled, "False", "false");
    jsAddItemToSelect(enabled, "True", "true");

    var connMode = document.getElementById("connMode");
    jsAddItemToSelect(connMode, "Local_To_Remote_Client", "1");
    jsAddItemToSelect(connMode, "Remote_To_Local_Client", "2");
    jsAddItemToSelect(connMode, "Local_Server", "3");

    var connType = document.getElementById("connType");
    jsAddItemToSelect(connType, "TCP_IP_Mode", "1");
    jsAddItemToSelect(connType, "UDP_Mode", "2");
    jsAddItemToSelect(connType, "Serial_Mode", "3");
    jsAddItemToSelect(connType, "HTTP_Mode", "4");

    var deviceId = document.getElementById("deviceId");
    jsAddItemToSelect(deviceId, "Charging", "1");
    jsAddItemToSelect(deviceId, "Screen", "2");
    jsAddItemToSelect(deviceId, "Sensor", "3");
    jsAddItemToSelect(deviceId, "NBIoT", "4");
    jsAddItemToSelect(deviceId, "LightingShow", "5");

    var factoryId = document.getElementById("factoryId");
    //
    if (deviceId.value == "1") 
    {
        jsAddItemToSelect(factoryId, "WanMa", "1");
        jsAddItemToSelect(factoryId, "NanRui", "2");
        jsAddItemToSelect(factoryId, "JuDian", "3");
    }
    if (deviceId.value == "2") 
    {
        jsAddItemToSelect(factoryId, "SCCS", "1");
    }
    if (deviceId.value == "3") 
    {
        jsAddItemToSelect(factoryId, "HongSui", "1");
        jsAddItemToSelect(factoryId, "XinPuHui", "2");
        jsAddItemToSelect(factoryId, "Frt", "3");
        jsAddItemToSelect(factoryId, "ZhiXiang", "4");
    }
    if (deviceId.value == "4") 
    {
        jsAddItemToSelect(factoryId, "LoraWan", "1");
    }
    if (deviceId.value == "5") 
    {
        jsAddItemToSelect(factoryId, "EXC", "1");
    }
    var versionId = document.getElementById("versionId");
    jsAddItemToSelect(versionId, "V1", "1");
    var deviceKey = document.getElementById("deviceKey");
    jsAddItemToSelect(deviceKey, "NULL", "null");

});

function deviceIdchange(deviceIdvalue) 
{
    var objSelect = document.getElementById("factoryId");
    if (deviceIdvalue == "1") 
    {
        jsRemoveItemFromSelect(objSelect);
        jsAddItemToSelect(factoryId, "WanMa", "1");
        jsAddItemToSelect(factoryId, "NanRui", "2");
        jsAddItemToSelect(factoryId, "JuDian", "3");
        $('.selectpicker').selectpicker('refresh');
    }
    if (deviceIdvalue == "2") 
    {
        jsRemoveItemFromSelect(objSelect);
        jsAddItemToSelect(objSelect, "SCCS", "1");
        $('.selectpicker').selectpicker('refresh');
    }
    if (deviceIdvalue == "3") 
    {
        jsRemoveItemFromSelect(objSelect);
        jsAddItemToSelect(factoryId, "HongSui", "1");
        jsAddItemToSelect(factoryId, "XinPuHui", "2");
        jsAddItemToSelect(factoryId, "Frt", "3");
        jsAddItemToSelect(factoryId, "ZhiXiang", "4");
        $('.selectpicker').selectpicker('refresh');
    }
    if (deviceIdvalue == "4") 
    {
        jsRemoveItemFromSelect(objSelect);
        jsAddItemToSelect(factoryId, "LoraWan", "1");
        $('.selectpicker').selectpicker('refresh');
    }
    if (deviceIdvalue == "5") 
    {
        jsRemoveItemFromSelect(objSelect);
        jsAddItemToSelect(factoryId, "EXC", "1");
        $('.selectpicker').selectpicker('refresh');
    }
}

$.validator.setDefaults(
    {
    submitHandler: function () {
        alert("Submitted!");
        form.submit();
    }
});

$(document).ready(function () 
{
    $("#deviceform").validate(
        {
        rules: 
        {
            name: "required",
            address: "required",
            port: 
            {
                required: true,
                digits: true
            },
            timeout: 
            {
                required: true,
                digits: true
            }
        },
        messages: 
        {
            name: "Please enter devicename",
            address: "Please enter address",
            port: 
            {
                required: "Please enter port",
                digits:"Please enter port of right format"
            },
            timeout: 
            {
                required: "Please enter timeout",
                digits: "Please enter timeout of right format"
            },
        },
        errorElement: "em",
        errorPlacement: function (error, element) 
        {
            // Add the `help-block` class to the error element
            error.addClass("help-block");

            if (element.prop("type") === "checkbox") 
            {
                error.insertAfter(element.parent("label"));
            } else {
                error.insertAfter(element);
            }
        },
        highlight: function (element, errorClass, validClass) 
        {
            $(element).parents(".col-sm-5").addClass("has-error").removeClass("has-success");
        },
        unhighlight: function (element, errorClass, validClass) {
            $(element).parents(".col-sm-5").addClass("has-success").removeClass("has-error");
        }
    });
});

// 1.判断select选项中 是否存在Value="paraValue"的Item       
function jsSelectIsExitItem(objSelect, objItemValue) {
    var isExit = false;
    for (var i = 0; i < objSelect.options.length; i++) {
        if (objSelect.options[i].value == objItemValue) {
            isExit = true;
            break;
        }
    }
    return isExit;
}

// 2.向select选项中 加入一个Item        
function jsAddItemToSelect(objSelect, objItemText, objItemValue) {
    //判断是否存在       
    if (jsSelectIsExitItem(objSelect, objItemValue)) {
        //alert("该Item的Valueֵ值已经存在");
    } else {
        var varItem = new Option(objItemText, objItemValue);
        objSelect.options.add(varItem);
        //alert("成功加入");
    }
}

// 3.从select选项中 删除Item        
function jsRemoveItemFromSelect(objSelect) {
    //判断是否存在  
    var len = objSelect.options.length;
    for (var i = len-1; i >=0; i--) {
        if (objSelect.options[i].value !=null) {
             objSelect.options.remove(i);
                
        }
    }
}    


// 4.删除select中选中的项    
function jsRemoveSelectedItemFromSelect(objSelect) {
    var length = objSelect.options.length - 1;
    for (var i = length; i >= 0; i--) {
        if (objSelect[i].selected == true) {
            objSelect.options[i] = null;
        }
    }
}

// 5.修改select选项中 value="paraValue"的text为"paraText"        
function jsUpdateItemToSelect(objSelect, objItemText, objItemValue) {
    //判断是否存在       
    if (jsSelectIsExitItem(objSelect, objItemValue)) {
        for (var i = 0; i < objSelect.options.length; i++) {
            if (objSelect.options[i].value == objItemValue) {
                objSelect.options[i].text = objItemText;
                break;
            }
        }
    }
}

// 6.设置select中text="paraText"的第一个Item为选中        
function jsSelectItemByValue(objSelect, objItemText) {
    //判断是否存在        
    var isExit = false;
    for (var i = 0; i < objSelect.options.length; i++) {
        if (objSelect.options[i].text == objItemText) {
            objSelect.options[i].selected = true;
            isExit = true;
            break;
        }
    }
}

