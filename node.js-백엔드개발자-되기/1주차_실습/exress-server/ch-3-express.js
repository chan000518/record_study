const express = require("express");
const app = express();
let posts = [];

// app.use([path,] callback [, callback...])
app.use(express.json());

app.use(express.urlencoded({extended : true}));

app.get("/", (req,res) => {
    res.json(posts);
});

app.post("/post",(req,res)=>{
    // 구조 분해 할당 : 객체의 속성을 분해하여 그 값을 개별 변수에 할당
    const { title, name, text } = req.body; // 딕셔너리인 이유 -> http의 body는 딕셔너리
    posts.push({id: posts.length +1, title, name, text, createDate: Date()});
    res.json({ title, name, text });
});

app.delete("/posts/:id", (req,res) => {
    const id = req.params.id;
    const filteredPosts = posts.filter((post) => post.id !== +id) //+:숫자로 바꿔주는 단항 연산자
    const isLengthChanged = posts.length !== filteredPosts.length;
    posts = filteredPosts;
    if (isLengthChanged) {
        res.json("OK");
        return;
    }
    res.json("NOT CHANGED");
});

app.listen(3000, () => {
    console.log("welcome");
})