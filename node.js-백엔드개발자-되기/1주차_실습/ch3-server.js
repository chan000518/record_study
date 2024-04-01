const http = require("http");
const url = require("url");

http
    .createServer((req,res) => {
        const path = url.parse(req.url, true).pathname;
        res.setHeader("Content-Type", "text/html; charset=utf-8")
        if (path in urlMap) {
            urlMap[path](req,res);
        }else{
            notFound(req,res);
        }
    })
    .listen("3000", () => console.log(""))

const user = (req,res) => {
    const userInfo = url.parse(req.url, true).query;
    res.end(`[user] name: ${userInfo.name}, age: ${userInfo.age}`)
}
const feed = (req,res) => {
    res.end(`
    <div>
        <ul>
            <li>안녕1</li>
            <li>안녕2</li>
            <li>안녕3</li>
            <li>안녕4</li>
        </ul>
    </div>
    `)
}
const notFound = (req,res) => {
    res.statusCode = 404;
    res.end("404 page")
}

const urlMap = {
    "/": (req,res) => res.end("HOME"),
    "/user": user,
    "/feed": feed,
};