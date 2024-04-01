const http = require("http");
const server = http.createServer((req,res) => { // 콜백 함수의 인자 req,res
    res.setHeader("Content-Type", "text/html; charset=utf-8");
    res.end("통신 ok")
});

server.listen("3000", () => console.log("ok 서버 시작"))
