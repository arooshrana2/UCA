var count = 3;

let add = () => {
    if($('#Roll')[0].value==""||$('#Name')[0].value==""||
    $('#Stream')[0].value==""||$('#PO')[0].value==""){
        fillAll();
    }
    else if(search($('#Roll')[0].value) == 1){
        alert("The roll number of multiple students cannot be same!!");
    }
    else{
        let rollTest = /^[0-9]{10}$/.test($('#Roll')[0].value);
        let nameTest = /[a-z A-Z]+/.test($('#Name')[0].value);
        let poTest = /[0-9]{4}$/.test($('#PO')[0].value);
        let streamTest = /[A-Z a-z]+/.test($('#Stream')[0].value);

        if(!rollTest){
            alert("Roll number must be of 10 digits and must include only integers!!");
            return;
        }
        if(!nameTest){
            alert("Name must include only Alphabets!!");
            return;
        }
        if(!poTest){
            alert("Year must include only integers of length four!!");
            return;
        }
        if(!streamTest){
            alert("Stream must include only Alphabets!!");
            return;
        }

        let tab = $("#table");
        tab.append(`<tr>
                    <td><input type = 'checkbox' name='box' class='box'> </td>
                    <td>${$('#Roll')[0].value}</td>
                    <td>${$('#Name')[0].value}</td>
                    <td>${$('#PO')[0].value}</td>
                    <td>${$('#Stream')[0].value}</td>
                </tr>`);
                count++;
                setValues();
    }
    
}

let checkPattern = ()=>{
    if(!($("#Name").value).test(name)){
        alert("Enter valid value for Name: only alphabets");
        return false;
    }
}

let del = () => {
    let chck = $('td input:checked');
    if(chck.length > 0){
        count = count - chck.length;
        chck.closest('tr').remove();
        if($('th input:checked').is(':checked')){
            $('th input:checked').prop('checked', false);
        }
    }
    else
        alert("Select rows to be deleted!!")
}

let edit = () =>{
    let not = 0;
    let no = $('#Roll')[0].value;
    if(no==""){
        alert("Enter the Roll No!!");
        return;
    }
    let rows = $('tr');
    if($("#Name")[0].value != "" || $("#Stream")[0].value != "" || $("#PO")[0].value != ""){
        for(let i in rows){
            if(i=="length") { not = 1; break;}
            let num = rows[i].children[1].innerHTML;
            if(no == num){
                if($("#Name")[0].value != "")
                    rows[i].children[2].innerHTML = $("#Name")[0].value;
                if($("#PO")[0].value != "")
                    rows[i].children[3].innerHTML = $("#PO")[0].value;
                if($("#Stream")[0].value != "")
                    rows[i].children[4].innerHTML = $("#Stream")[0].value;
                break;
            }
        }
        if(not == 1){
            alert("No such Roll Number exist..! Recheck and try again..!");    
        }
    }
    if(not==0)
        setValues();
}

let check = ()=>{
    let len = $('td input:checked').length;
    if(len == count){
        $('#Check').prop("checked", true);
    }
    else{
        $('#Check').prop("checked", false);
    }
}

let checkAll = (cb) => {
    let checkBoxes = document.getElementsByName('box');
    if(cb.is(':checked')){
        $("input[class='box']").prop("checked", true);
    }
    else{
        $("input[name='box']").prop("checked", false);
    }
}

let fillAll = ()=>{
    alert("Fill all the text fields with appropriate values.!");
}

let setValues = ()=>{
    $("#Roll").prop("placeholder", "Roll No").val("").blur();
    $("#Name").prop("placeholder", "Name").val("").blur();
    $("#PO").prop("placeholder", "Passing Out").val("").blur();
    $("#Stream").prop("placeholder", "Stream").val("").blur();
}

let search = (no) => {
    let rows = document.getElementsByTagName('tr');
    for(let i in rows){
        if(i == "length") break;
        let num = rows[i].children[1].innerHTML;
        if(num == no){
            return 1;
        }
    }
    return 0;
}
