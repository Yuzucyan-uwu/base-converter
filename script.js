function digitToChar(x) {
    if (x < 10) return String.fromCharCode(48 + x);
    return String.fromCharCode(65 + x - 10);
}

function convert() {
    let num = parseInt(document.getElementById("decimal").value);
    let base = parseInt(document.getElementById("base").value);

    if (isNaN(num) || isNaN(base)) {
        document.getElementById("result").innerText = "Invalid input!";
        return;
    }

    if (base < 2 || base > 35) {
        document.getElementById("result").innerText = "Base must be 2~35!";
        return;
    }

    if (num === 0) {
        document.getElementById("result").innerText = "0";
        return;
    }

    let neg = false;
    if (num < 0) {
        neg = true;
        num = -num;
    }

    let res = "";
    while (num > 0) {
        let r = num % base;
        res = digitToChar(r) + res;
        num = Math.floor(num / base);
    }

    if (neg) res = "-" + res;

    document.getElementById("result").innerText = res;
}