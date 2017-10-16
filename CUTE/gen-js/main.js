var transport = new Thrift.Transport("http://localhost:9090");
var protocol  = new Thrift.Protocol(transport);
var client    = new DemoServletClient(protocol);

var n = 2;
var m = 2;

var rawInput;
var candidate;
var realInput;

var res;

var sparqlandresult;
var ansNum, curAnsNum;

var factsNum, curFactsNum;

var negInput;
var negRes;
var negFactsNum, curNegFactsNum;

function submitStep1() {
    if (!checkInput()) {
        alert("The input should not be blank!")
        return;
    }


    rawInput = new Array(n);

    const table = document.getElementById("input");
    const trs = table.children;

    for (let i = 0; i < n; i++) {
        let tr = trs[i];
        let tds = tr.children;
        rawInput[i] = new Array(m);
        for (let j = 0; j < m; j++) {
            let td = tds[j];
            rawInput[i][j] = td.children[0].value;
        }
    }

    candidate = client.disambiguation(rawInput);

    destructStep2();
    constructStep2();
    
}

function submitStep2() {

    realInput = new Array(n);

    for (let i = 0; i < n; i++) {
        realInput[i] = new Array(m);
        for (let j = 0; j < m; j++) {
            let candidates = document.getElementsByName("candidate_" + i.toString() + j.toString());
            for (let k = 0; k < candidates.length; k++)
                if (candidates[k].checked) {
                    realInput[i][j] = candidates[k].value;
                    break;
                }
        }
    }

    res = client.findCommonInfo(realInput, true);

    destructStep3();
    constructStep3();

}

function submitStep3() {


    let up = new CommonInfo();
    up.p = res.p;

    up.t = new Array();
    for (let i = 0; i < m; i++) {
        let tmp = new Types();
        tmp.types = new Array();

        let inputs = document.getElementsByName("commonTypes_" + i.toString());
        for (let j = 0; j < inputs.length; j++) {
            let input = inputs[j];
            let oneType = new OneType();
            if (input.checked) {
                oneType.typeName = input.value;
                tmp.types.push(oneType);
            }
        }
        up.t.push(tmp);
    }
    
    up.f = new Array();
    for (let i = 0; i < m; i++) {
        let tmp = new Facts();
        tmp.facts = new Array();

        let inputs = document.getElementsByName("commonFacts_" + i.toString());
        for (let j = 0; j < inputs.length; j++) {
            let input = inputs[j];
            if (input.checked) {
                let str = input.value;
                let s, p, o;
                let oneFact = new OneFact();
                if (str[0] === '0') {
                    str = str.substring(1);
                    p = (str.split("__"))[0];
                    o = (str.split("__"))[1];
                    oneFact.direction = false;
                    oneFact.P = p;
                    oneFact.SorO = o;
                }
                else {
                    str = str.substring(1);
                    s = (str.split("__"))[0];
                    p = (str.split("__"))[1];
                    oneFact.direction = true;
                    oneFact.SorO = s;
                    oneFact.P = p;
                }
                tmp.facts.push(oneFact);
            }
        }
        up.f.push(tmp);
    }
    

    sparqlandresult = client.query(up, realInput);

    destructStep4();
    constructStep4();

}


function submitStep4() {


    negInput = new Array();

    const inputs = document.getElementsByName("results");
    let flag = false;
    for (let i = 0; i < inputs.length; i++) {
        if (inputs[i].checked) {
            flag = true;
            negInput.push(inputs[i].value.split("__"));
        }
    }

    if (!flag) {
        alert("You have to choose at least one rejective result!");
        return;
    }

    negRes = client.findCommonInfo(negInput, false);

    destructStep5();
    constructStep5();

}

function submitStep5() {

    let up = new NegCommonInfo();

    up.hasKeywords = false;
    up.k = new Array();
    
    for (let i = 0; i < m; i++) {
        let tmp = new Keywords();
        tmp.keywords = new Array();

        let inputs = document.getElementsByName("negKeywords_" + i.toString());
        for (let j = 0; j < inputs.length; j++) {
            let input = inputs[j];

            if (input.checked) {
                up.hasKeywords = true;
                tmp.keywords.push(input.value);
            }
        }
        up.k.push(tmp);

    }


    up.hasProperty = false;

    up.t = new Array();
    for (let i = 0; i < m; i++) {
        let tmp = new Types();
        tmp.types = new Array();

        let inputs = document.getElementsByName("negCommonTypes_" + i.toString());
        for (let j = 0; j < inputs.length; j++) {
            let input = inputs[j];
            let oneType = new OneType();
            if (input.checked) {
                up.hasProperty = true;
                oneType.typeName = input.value;
                tmp.types.push(oneType);
            }
        }
        up.t.push(tmp);
    }
    
    up.f = new Array();
    for (let i = 0; i < m; i++) {
        let tmp = new Facts();
        tmp.facts = new Array();

        let inputs = document.getElementsByName("negCommonFacts_" + i.toString());
        for (let j = 0; j < inputs.length; j++) {
            let input = inputs[j];
            if (input.checked) {
                up.hasProperty = true;
                let str = input.value;
                let s, p, o;
                let oneFact = new OneFact();
                if (str[0] === '0') {
                    str = str.substring(1);
                    p = (str.split("__"))[0];
                    o = (str.split("__"))[1];
                    oneFact.direction = false;
                    oneFact.P = p;
                    oneFact.SorO = o;
                }
                else {
                    str = str.substring(1);
                    s = (str.split("__"))[0];
                    p = (str.split("__"))[1];
                    oneFact.direction = true;
                    oneFact.SorO = s;
                    oneFact.P = p;
                }
                tmp.facts.push(oneFact);
            }
        }
        up.f.push(tmp);
    }

    if (!up.hasProperty && !up.hasKeywords) {
        alert("You have to choose at least one property or keyword of the negtive result(s)!");
        return;
    }


    sparqlandresult = client.queryWithNeg(up, sparqlandresult.sparql);

    destructStep4();
    constructStep4();
}