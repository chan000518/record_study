const http = require("http");
let count = 0;

const server = http.createServer((req,res) => { // 콜백 함수의 인자 req,res
    log(); //코드가 이상해 ㅋㅋ
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain; charset=utf-8");
    res.write("hello\n");
    setTimeout(() =>{
        res.end("통신 끝")
        console.log("통신 종료",count) // 통신이 밀리는 만큼 나중에 출력 비동기이지 처리 속도 0 x
    },2000);
}
);

function log(){
    console.log((count+=1));
}

server.listen(8000);
