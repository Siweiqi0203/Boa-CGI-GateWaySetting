/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-30 13:53:57 
 * @Last Modified by: Weiqi Si
 * @Last Modified time: 2018-09-30 14:11:35
 */

// JavaScript source code
$(function () 
{
    $.ajaxSetup({ cache: false }); 
    $.ajax(
        {
        type: "GET",
        url: "/data/test.json",
        dataType: "json",
        success: function (result) 
        {
            addoption(result);
        }
    });
    $('.selectpicker').selectpicker('refresh');
});

function addoption(result) 
{
    var name = document.getElementById("name");
    $.each(result.devices, function (i, obj) 
    {
        jsAddItemToSelect(name, obj['name'],i);
    });
    $('.selectpicker').selectpicker('refresh');

}

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
    } else 
    {
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
function jsSelectItemByValue(objSelect, objItemText) 
{
    //判断是否存在        
    var isExit = false;
    for (var i = 0; i < objSelect.options.length; i++) 
    {
        if (objSelect.options[i].text == objItemText) 
        {
            objSelect.options[i].selected = true;
            isExit = true;
            break;
        }
    }
}
