function htmlEncode(str) {   
    let s = "";   
    if (str.length === 0) return "";
    s = str.replace(/&/g, "&#38;");
    s = s.replace(/</g, "&lt;");
    s = s.replace(/>/g, "&gt;");
    s = s.replace(/ /g, "&nbsp;");
    s = s.replace(/\'/g, "&#39;");
    s = s.replace(/\"/g, "&quot;");
    s = s.replace(/\n/g, "<br />");
    return s;   
}

function addRow() {
    const table = document.getElementById("input");
    const tr = document.createElement("tr");

    for (let i = 0; i < m; i++) {
        let td = document.createElement("td");
        let input = document.createElement("input");
        input.setAttribute("type", "text");
        input.setAttribute("name", "entity_" + n.toString() + i.toString());
        td.appendChild(input);
        tr.appendChild(td);
    }
    table.appendChild(tr);
    n++;
}

function addColumn() {
    const table = document.getElementById("input");
    const trs = table.children;

    for (let i = 0; i < trs.length; i++) {
        let tr = trs[i];
        let td = document.createElement("td");
        let input = document.createElement("input");
        input.setAttribute("type", "text");
        input.setAttribute("name", "entity_" + i.toString() + m.toString());
        td.appendChild(input);
        tr.appendChild(td);
    }
    m++;
}

function removeRow() {
    if (n == 1) return;
    const table = document.getElementById("input");
    const tr = table.children[table.children.length - 1];

    if(tr.parentNode) {
        tr.parentNode.removeChild(tr);
    }
    n--;
}

function removeColumn() {
    if (m == 1) return;
    const table = document.getElementById("input");
    const trs = table.children;

    for (let i = 0; i < trs.length; i++) {
        let tr = trs[i];
        let td = tr.children[tr.children.length - 1];
        if(td.parentNode) {
            td.parentNode.removeChild(td);
        }
    }
    m--;
}


/**
 * Randomize array element order in-place.
 * Using Durstenfeld shuffle algorithm.
 */
function shuffleArray(array) {
    for (var i = array.length - 1; i > 0; i--) {
        var j = Math.floor(Math.random() * (i + 1));
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    return array;
}

function checkInput() {
    const table = document.getElementById("input");
    const trs = table.children;

    for (let i = 0; i < n; i++) {
        let tr = trs[i];
        let tds = tr.children;
        for (let j = 0; j < m; j++) {
            let td = tds[j];
            if (td.children[0].value.length == 0) return false;
        }
    }

    return true;
}

function constructStep2() {
    const body = document.getElementsByTagName("body").item(0);
    const divStep2 = document.createElement("div");
    divStep2.setAttribute("id", "step2");

    divStep2.appendChild(document.createElement("hr"));

    for (let i = 0; i < n; i++) {

        let oneRowCandidate = candidate[i].row;
        for (let j = 0; j < m; j++) {
            let cc = oneRowCandidate[j].c;
            let h3 = document.createElement("h3");
            h3.innerHTML = rawInput[i][j] + ":";
            divStep2.appendChild(h3);
            for (let k = 0; k < 5; k++) {

                let input = document.createElement("input");
                input.setAttribute("type", "radio");
                input.setAttribute("name", "candidate_" + i.toString() + j.toString());
                input.setAttribute("value", cc[k]);
                if (k == 0) input.checked = true;
                divStep2.appendChild(input);

                let text = document.createTextNode(cc[k]);
                divStep2.appendChild(text);

                divStep2.appendChild(document.createElement("br"));
            }
            divStep2.appendChild(document.createElement("br"));
        }
    }

    const submit = document.createElement("button");
    submit.setAttribute("type", "submit");
    submit.setAttribute("onClick", "submitStep2();");
    const text = document.createTextNode("Submit");
    submit.appendChild(text);
    divStep2.appendChild(submit);

    body.appendChild(divStep2);
}

function destructStep2() {
    const step2 = document.getElementById("step2");
    if(step2 != null && step2.parentNode) {
        step2.parentNode.removeChild(step2);
    }
    destructStep3();
}

function constructStep3Pattern(divStep3) {
    // contruct types part
    const divStep3Pattern = document.createElement("div");
    divStep3Pattern.setAttribute("id", "step3Pattern");

    const pattern = res.p;

    const h3 = document.createElement("h3");
    h3.innerHTML = "Pattern:";
    divStep3Pattern.appendChild(h3);

    const table = document.createElement("table");
    const tbody = document.createElement("tbody");

    for (let i = 0; i < pattern.length; i++) {
        let tr = document.createElement("tr");
        let td;
        let text;

        td = document.createElement("td");
        text = document.createTextNode(pattern[i].s);
        td.appendChild(text);
        tr.appendChild(td);

        td = document.createElement("td");
        text = document.createTextNode(pattern[i].p);
        td.appendChild(text);
        tr.appendChild(td);

        td = document.createElement("td");
        text = document.createTextNode(pattern[i].o);
        td.appendChild(text);
        tr.appendChild(td);

        tbody.appendChild(tr);
    }
    table.appendChild(tbody);

    divStep3Pattern.appendChild(table);

    divStep3.appendChild(divStep3Pattern);
}

function constructStep3Types(divStep3) {
    // contruct types part
    const divStep3Types = document.createElement("div");
    divStep3Types.setAttribute("id", "step3Types");

    const ts = res.t;
    for (let i = 0; i < m; i++) {

        let h3 = document.createElement("h3");
        h3.innerHTML = "Types Column " + i.toString() + ":";
        divStep3Types.appendChild(h3);

        for (let j = 0; j < ts[i].types.length; j++) {
            let input = document.createElement("input");
            input.setAttribute("type", "checkbox");
            input.setAttribute("name", "commonTypes_" + i.toString());
            input.setAttribute("value", ts[i].types[j].typeName);
            divStep3Types.appendChild(input);

            text = document.createTextNode(ts[i].types[j].typeName);
            divStep3Types.appendChild(text);

            divStep3Types.appendChild(document.createElement("br"));
        }
        divStep3Types.appendChild(document.createElement("br"));
    }
    divStep3.appendChild(divStep3Types);
}

function constructStep3Facts(divStep3) {
    // contruct facts part
    const divStep3Facts = document.createElement("div");
    divStep3Facts.setAttribute("id", "step3Facts");

    const fs = res.f;

    factsNum = new Array(m);
    curFactsNum = new Array(m);
    

    for (let i = 0; i < m; i++) {

        let h3 = document.createElement("h3");
        h3.innerHTML = "Facts Column " + i.toString() + ":";
        divStep3Facts.appendChild(h3);

        let table = document.createElement("table");
        let tr, th, text;

        let thead = document.createElement("thead");
        tr = document.createElement("tr");

        th = document.createElement("th");
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("s");
        th.appendChild(text);
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("p");
        th.appendChild(text);
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("o");
        th.appendChild(text);
        tr.appendChild(th);

        thead.appendChild(tr);
        table.appendChild(thead);

        let tbody = document.createElement("tbody");
        tbody.setAttribute("id", "facts" + i.toString());

        shuffleArray(fs[i].facts);

        factsNum[i] = fs[i].facts.length;
        curFactsNum[i] = 0;


        for (let j = 0; j < Math.min(20, factsNum[i]); j++) {

            tr = document.createElement("tr");
            td = document.createElement("td");

            let input = document.createElement("input");
            input.setAttribute("type", "checkbox");
            input.setAttribute("name", "commonFacts_" + i.toString());

            if (fs[i].facts[j].direction === false) {
                input.setAttribute("value", "0" + fs[i].facts[j].P + "__" + fs[i].facts[j].SorO);
                td.appendChild(input);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode("?v" + i.toString());
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].P);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].SorO);
                td.appendChild(text);
                tr.appendChild(td);
            }
            else {

                input.setAttribute("value", "1" + fs[i].facts[j].SorO + "__" + fs[i].facts[j].P);
                td.appendChild(input);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].SorO);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].P);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode("?v" + i.toString());
                td.appendChild(text);
                tr.appendChild(td);
            }

            tbody.appendChild(tr);

            curFactsNum[i] = j + 1;
        }
        table.appendChild(tbody);
        divStep3Facts.appendChild(table);

        let more = document.createElement("button");
        more.onclick = function() { addMoreFacts(i); }
        text = document.createTextNode("Get more facts");
        more.appendChild(text);
        divStep3Facts.appendChild(more);
    }


    divStep3.appendChild(divStep3Facts);
}

function addMoreFacts(i) {
    if (curFactsNum[i] === factsNum[i]) {
        alert("No more facts!");
        return;
    }

    const fs = res.f;

    const tbody = document.getElementById("facts" + i.toString());
    let cur = curFactsNum[i];

    for (let j = cur; j < Math.min(cur + 20, factsNum[i]); j++) {

        tr = document.createElement("tr");
        td = document.createElement("td");

        let input = document.createElement("input");
        input.setAttribute("type", "checkbox");
        input.setAttribute("name", "commonFacts_" + i.toString());

        if (fs[i].facts[j].direction === false) {
            input.setAttribute("value", "0" + fs[i].facts[j].P + "__" + fs[i].facts[j].SorO);
            td.appendChild(input);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode("?v" + i.toString());
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].P);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].SorO);
            td.appendChild(text);
            tr.appendChild(td);
        }
        else {

            input.setAttribute("value", "1" + fs[i].facts[j].SorO + "__" + fs[i].facts[j].P);
            td.appendChild(input);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].SorO);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].P);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode("?v" + i.toString());
            td.appendChild(text);
            tr.appendChild(td);
        }

        tbody.appendChild(tr);

        curFactsNum[i] = j + 1;
    }

}

function constructStep3() {
    const body = document.getElementsByTagName("body").item(0);
    const divStep3 = document.createElement("div");
    divStep3.setAttribute("id", "step3");

    divStep3.appendChild(document.createElement("hr"));

    constructStep3Pattern(divStep3);
    constructStep3Types(divStep3);
    constructStep3Facts(divStep3);


    const query = document.createElement("button");
    query.setAttribute("onClick", "submitStep3();");
    const text = document.createTextNode("Query");
    query.appendChild(text);
    divStep3.appendChild(query);

    body.appendChild(divStep3);
}

function destructStep3() {
    const step3 = document.getElementById("step3");
    if(step3 != null && step3.parentNode) {
        step3.parentNode.removeChild(step3);
    }
    destructStep4();
}

function constructStep4Sparql(divStep4) {
    const divStep4Sparql = document.createElement("div");
    divStep4Sparql.setAttribute("id", "step4Sparql");

    const h3 = document.createElement("h3");
    h3.innerHTML = "SPARQL:";
    divStep4Sparql.appendChild(h3);

    const pre = document.createElement("pre");
    pre.innerHTML = htmlEncode(sparqlandresult.sparql);
    divStep4Sparql.appendChild(pre);

    divStep4.appendChild(divStep4Sparql);
}

function constructStep4Result(divStep4) {
    const divStep4Result = document.createElement("div");
    divStep4Result.setAttribute("id", "step4Result");

    const h3 = document.createElement("h3");
    h3.innerHTML = "Result:";
    divStep4Result.appendChild(h3);

    let tr, th, td, text;
    const table = document.createElement("table");
    const thead = document.createElement("thead");

    tr = document.createElement("tr");

    th = document.createElement("th");
    text = document.createTextNode("rejective");
    th.appendChild(text);
    tr.appendChild(th);

    for (let i = 0; i < m; i++) {
        th = document.createElement("th");
        text = document.createTextNode("?v" + i.toString());
        th.appendChild(text);
        tr.appendChild(th);
    }

    thead.appendChild(tr);
    table.appendChild(thead);

    const tbody = document.createElement("tbody");
    tbody.setAttribute("id", "results");

    ansNum = sparqlandresult.result.length;
    shuffleArray(sparqlandresult.result);

    for (let i = 0; i < Math.min(20, ansNum); i++) {
        tr = document.createElement("tr");
        td = document.createElement("td");
        let input = document.createElement("input");
        input.setAttribute("type", "checkbox");
        input.setAttribute("name", "results");

        let strValue = "";
        for (let j = 0; j < m; j++)
            if (j !== m - 1)
                strValue += sparqlandresult.result[i].row[j] + "__";
            else
                strValue += sparqlandresult.result[i].row[j];

        input.setAttribute("value", strValue);
        td.appendChild(input);
        tr.appendChild(td);

        for (let j = 0; j < m; j++) {
            td = document.createElement("td");
            text = document.createTextNode(sparqlandresult.result[i].row[j]);
            td.appendChild(text);
            tr.appendChild(td);
        }

        tbody.appendChild(tr);
        curAnsNum = i + 1;
    }
    table.appendChild(tbody);
    divStep4Result.appendChild(table);

    const more = document.createElement("button");
    more.setAttribute("onClick", "addMoreResults();");
    text = document.createTextNode("Get more results");
    more.appendChild(text);
    divStep4Result.appendChild(more);

    divStep4.appendChild(divStep4Result);
}

function addMoreResults() {
    if (curAnsNum === ansNum) {
        alert("No more results!");
        return;
    }

    const tbody = document.getElementById("results");

    let cur = curAnsNum;
    for (let i = cur; i < Math.min(cur + 20, ansNum); i++) {
        let tr = document.createElement("tr");
        let td = document.createElement("td");
        let input = document.createElement("input");
        input.setAttribute("type", "checkbox");
        input.setAttribute("name", "results");
        let strValue = "";
        for (let j = 0; j < m; j++)
            if (j !== m - 1)
                strValue += sparqlandresult.result[i].row[j] + "__";
            else
                strValue += sparqlandresult.result[i].row[j];

        input.setAttribute("value", strValue);

        td.appendChild(input);
        tr.appendChild(td);

        for (let j = 0; j < m; j++) {
            td = document.createElement("td");
            text = document.createTextNode(sparqlandresult.result[i].row[j]);
            td.appendChild(text);
            tr.appendChild(td);
        }

        tbody.appendChild(tr);
        curAnsNum = i + 1;
    }
}

function constructStep4() {
    const body = document.getElementsByTagName("body").item(0);
    const divStep4 = document.createElement("div");
    divStep4.setAttribute("id", "step4");

    divStep4.appendChild(document.createElement("hr"));

    constructStep4Sparql(divStep4);
    constructStep4Result(divStep4);


    const submit = document.createElement("button");
    submit.setAttribute("type", "submit");
    submit.setAttribute("onClick", "submitStep4();");
    const text = document.createTextNode("Submit");
    submit.appendChild(text);
    divStep4.appendChild(submit);

    body.appendChild(divStep4);
}

function destructStep4() {
    const step4 = document.getElementById("step4");
    if(step4 != null && step4.parentNode) {
        step4.parentNode.removeChild(step4);
    }
    destructStep5();
}

function constructStep5Keywords(divStep5) {
    // contruct keywords part
    const divStep5Keywords = document.createElement("div");
    divStep5Keywords.setAttribute("id", "step5Keywords");


    for (let i = 0; i < m; i++) {

        let h3 = document.createElement("h3");
        h3.innerHTML = "Negtive Keywords Column " + i.toString() + ":";
        divStep5Keywords.appendChild(h3);

        let ks = new Set();
        for (let j = 0; j < negInput.length; j++)
            ks.add(negInput[j][i]);

        for (let keyword of ks) {
            let input = document.createElement("input");
            input.setAttribute("type", "checkbox");
            input.setAttribute("name", "negKeywords_" + i.toString());
            input.setAttribute("value", keyword);
            divStep5Keywords.appendChild(input);

            text = document.createTextNode(keyword);
            divStep5Keywords.appendChild(text);

            divStep5Keywords.appendChild(document.createElement("br"));
        }

        divStep5Keywords.appendChild(document.createElement("br"));
    }
    divStep5.appendChild(divStep5Keywords);

}

function constructStep5Types(divStep5) {
    // contruct types part
    const divStep5Types = document.createElement("div");
    divStep5Types.setAttribute("id", "step5Types");

    const ts = negRes.t;
    for (let i = 0; i < m; i++) {

        let h3 = document.createElement("h3");
        h3.innerHTML = "Negtive Types Column " + i.toString() + ":";
        divStep5Types.appendChild(h3);

        for (let j = 0; j < ts[i].types.length; j++) {
            let input = document.createElement("input");
            input.setAttribute("type", "checkbox");
            input.setAttribute("name", "negCommonTypes_" + i.toString());
            input.setAttribute("value", ts[i].types[j].typeName);
            divStep5Types.appendChild(input);

            text = document.createTextNode(ts[i].types[j].typeName);
            divStep5Types.appendChild(text);

            divStep5Types.appendChild(document.createElement("br"));
        }
        divStep5Types.appendChild(document.createElement("br"));
    }
    divStep5.appendChild(divStep5Types);
}

function constructStep5Facts(divStep5) {
    // contruct facts part
    const divStep5Facts = document.createElement("div");
    divStep5Facts.setAttribute("id", "step5Facts");

    const fs = negRes.f;

    negFactsNum = new Array(m);
    curNegFactsNum = new Array(m);
    

    for (let i = 0; i < m; i++) {

        let h3 = document.createElement("h3");
        h3.innerHTML = "Negtive Facts Column " + i.toString() + ":";
        divStep5Facts.appendChild(h3);

        let table = document.createElement("table");
        let tr, th, text;

        let thead = document.createElement("thead");
        tr = document.createElement("tr");

        th = document.createElement("th");
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("s");
        th.appendChild(text);
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("p");
        th.appendChild(text);
        tr.appendChild(th);

        th = document.createElement("th");
        text = document.createTextNode("o");
        th.appendChild(text);
        tr.appendChild(th);

        thead.appendChild(tr);
        table.appendChild(thead);

        let tbody = document.createElement("tbody");
        tbody.setAttribute("id", "negFacts" + i.toString());

        shuffleArray(fs[i].facts);

        negFactsNum[i] = fs[i].facts.length;
        curNegFactsNum[i] = 0;


        for (let j = 0; j < Math.min(20, negFactsNum[i]); j++) {

            tr = document.createElement("tr");
            td = document.createElement("td");

            let input = document.createElement("input");
            input.setAttribute("type", "checkbox");
            input.setAttribute("name", "negCommonFacts_" + i.toString());

            if (fs[i].facts[j].direction === false) {
                input.setAttribute("value", "0" + fs[i].facts[j].P + "__" + fs[i].facts[j].SorO);
                td.appendChild(input);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode("?v" + i.toString());
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].P);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].SorO);
                td.appendChild(text);
                tr.appendChild(td);
            }
            else {

                input.setAttribute("value", "1" + fs[i].facts[j].SorO + "__" + fs[i].facts[j].P);
                td.appendChild(input);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].SorO);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode(fs[i].facts[j].P);
                td.appendChild(text);
                tr.appendChild(td);

                td = document.createElement("td");
                text = document.createTextNode("?v" + i.toString());
                td.appendChild(text);
                tr.appendChild(td);
            }

            tbody.appendChild(tr);

            curNegFactsNum[i] = j + 1;
        }
        table.appendChild(tbody);
        divStep5Facts.appendChild(table);

        let more = document.createElement("button");
        more.onclick = function() { addMoreNegFacts(i); }
        text = document.createTextNode("Get more facts");
        more.appendChild(text);
        divStep5Facts.appendChild(more);
    }


    divStep5.appendChild(divStep5Facts);
}

function addMoreNegFacts(i) {
    if (curNegFactsNum[i] === negFactsNum[i]) {
        alert("No more facts!");
        return;
    }

    const fs = negRes.f;

    const tbody = document.getElementById("negFacts" + i.toString());
    let cur = curNegFactsNum[i];

    for (let j = cur; j < Math.min(cur + 20, negFactsNum[i]); j++) {

        tr = document.createElement("tr");
        td = document.createElement("td");

        let input = document.createElement("input");
        input.setAttribute("type", "checkbox");
        input.setAttribute("name", "negCommonFacts_" + i.toString());

        if (fs[i].facts[j].direction === false) {
            input.setAttribute("value", "0" + fs[i].facts[j].P + "__" + fs[i].facts[j].SorO);
            td.appendChild(input);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode("?v" + i.toString());
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].P);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].SorO);
            td.appendChild(text);
            tr.appendChild(td);
        }
        else {

            input.setAttribute("value", "1" + fs[i].facts[j].SorO + "__" + fs[i].facts[j].P);
            td.appendChild(input);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].SorO);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode(fs[i].facts[j].P);
            td.appendChild(text);
            tr.appendChild(td);

            td = document.createElement("td");
            text = document.createTextNode("?v" + i.toString());
            td.appendChild(text);
            tr.appendChild(td);
        }

        tbody.appendChild(tr);

        curNegFactsNum[i] = j + 1;
    }

}


function constructStep5() {
    const body = document.getElementsByTagName("body").item(0);
    const divStep5 = document.createElement("div");
    divStep5.setAttribute("id", "step5");

    divStep5.appendChild(document.createElement("hr"));

    constructStep5Keywords(divStep5);
    constructStep5Types(divStep5);
    constructStep5Facts(divStep5);


    const reject = document.createElement("button");
    reject.setAttribute("onClick", "submitStep5();");
    const text = document.createTextNode("Reject");
    reject.appendChild(text);
    divStep5.appendChild(reject);

    body.appendChild(divStep5);
}


function destructStep5() {
    const step5 = document.getElementById("step5");
    if(step5 != null && step5.parentNode) {
        step5.parentNode.removeChild(step5);
    }
}
