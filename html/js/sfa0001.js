//array e variabili bglobali
var SSIDProtArray = ["Open","Wep","Wpa"];
var BrokerProtArray = ["Open","SSL","TLS"];
var DHCPArray = ["Static","Dynamic"];

//funzioni

function stato()
{
	ViewSSIDProt(document.getElementById("SSIDProt").innerHTML);
	ViewBrokerProt1(document.getElementById("ViewBrokerProt1").innerHTML);
	ViewBrokerProt2(document.getElementById("ViewBrokerProt1").innerHTML);
	ViewDHCPStatus(document.getElementById("StatoDHCP").innerHTML);
}

//Verifica uguaglianza password
function Validate() {
        var password = document.getElementById("PWD").value;
        var confirmPassword = document.getElementById("PWDC").value;
        if (password != confirmPassword) {
            alert("Passwords do not match.");
            return false;
        }
        return true;
    }

//----------  SSID   ----------------

function SelectSSIDProt(ProtKey)//ricavo la select per la selezione della protezione SSID, avendo cura di preselezionare il campo proveniente dall'impostazione attuale
{
	var myDiv = document.getElementById("SelectProt");//scrivo la select nell'elemento con id SelectProt

//creo la select
var selectList = document.createElement("select");
selectList.setAttribute("id", "SelectProt");
selectList.setAttribute("name", "__SL_P_U02");
myDiv.appendChild(selectList);

//creo le option
for (var i = 0; i < SSIDProtArray.length; i++) {
    var option = document.createElement("option");
    option.setAttribute("value", i);
    option.text = SSIDProtArray[i];
	if(i == ProtKey)
	{
		option.setAttribute("selected", "selected");//seleziono la voce in base al valore ritornato da CC3200
	}
    selectList.appendChild(option);
}
}


function ViewSSIDProt(ProtKey)//creo l'associazione nome<-Id per l'SSID
{
	for (var i = 0; i < SSIDProtArray.length; i++) {
    if(i == ProtKey)
	{
		document.getElementById("SSIDProt").innerHTML = SSIDProtArray[i];
	}
}
}

//------------ Broker Protection
function SelectBrokerProt(ProtKey1,ProtKey2)//ricavo la select per la selezione della protezione broker, avendo cura di preselezionare il campo proveniente dall'impostazione attuale
{
	var myDiv1 = document.getElementById("SelectProt1");//scrivo la select nell'elemento con id SelectProt
    //creo la select
    var selectList1 = document.createElement("select");
    selectList1.setAttribute("id", "SelectProt1");
    selectList1.setAttribute("name", "__SL_P_U13");
    myDiv1.appendChild(selectList1);
    
    //creo le option
    for (var i = 0; i < BrokerProtArray.length; i++) {
        var option1 = document.createElement("option");
        option1.setAttribute("value", i);
        option1.text = BrokerProtArray[i];
    	if(i == ProtKey1)
    	{
    		option1.setAttribute("selected", "selected");//seleziono la voce in base al valore ritornato da CC3200
    	}
        selectList1.appendChild(option1);
    }
    
    var myDiv2 = document.getElementById("SelectProt2");//scrivo la select nell'elemento con id SelectProt
    //creo la select
    var selectList2 = document.createElement("select");
    selectList2.setAttribute("id", "SelectProt2");
    selectList2.setAttribute("name", "__SL_P_U14");
    myDiv2.appendChild(selectList2);
    
    //creo le option
    for (var i = 0; i < BrokerProtArray.length; i++) {
        var option2 = document.createElement("option");
        option2.setAttribute("value", i);
        option2.text = BrokerProtArray[i];
    	if(i == ProtKey2)
    	{
    		option2.setAttribute("selected", "selected");//seleziono la voce in base al valore ritornato da CC3200
    	}
        selectList2.appendChild(option2);
    }
}

function ViewBrokerProt1(ProtKey1)//creo l'associazione nome<-Id per la protezione
{
	for (var i = 0; i < BrokerProtArray.length; i++) {
    if(i == ProtKey1)
	{
		document.getElementById("ViewBrokerProt1").innerHTML = BrokerProtArray[i];
	}
}
}

function ViewBrokerProt2(ProtKey2)//creo l'associazione nome<-Id per la protezione
{
	for (var i = 0; i < BrokerProtArray.length; i++) {
    if(i == ProtKey2)
	{
		document.getElementById("ViewBrokerProt2").innerHTML = BrokerProtArray[i];
	}
}
}

--------------- DHCP 

function RadioDHCP(Status)//ricavo i pulsanti radio per selezionare il tipo di DHCP
{
	var myDiv = document.getElementById("UsoDHCP");//scrivo la select nell'elemento con id UsoDHCP
myDiv.appendChild(Status);
//creo la select
/*var selectList = document.createElement("radio");
selectList.setAttribute("id", "StatoDHCP");
selectList.setAttribute("name", "__SL_P_U60");
myDiv.appendChild(selectList);*/

//creo i pulsanti
for (var i = 0; i < DHCPArray.length; i++) {
    var option = document.createElement("DHCPradio");
	option.setAttribute("type", "radio");
	option.setAttribute("name", "__SL_P_U60");
    option.setAttribute("value", i);
    option.text = DHCPArray[i];
	if(i == Status)
	{
		option.setAttribute("selected", "selected");//seleziono la voce in base al valore ritornato da CC3200
	}
    myDiv.appendChild(option);
}
}

function ViewDHCPStatus(DHCP)//creo l'associazione nome<-Id per la protezione
{
	for (var i = 0; i < DHCPArray.length; i++) {
    if(i == DHCP)
	{
		document.getElementById("StatoDHCP").innerHTML = BrokerProtArray[i];
	}
}
}