const express = require('express')
const app = express()


app.get('/user/login',(req,res)=>{
let query = req.query

if(query.us==='?'&&query.ps=='?'){
    res.send({"err":0,"msg":"login ok"})
    
}else{
    res.send({"err":-1,"msg":"login not ok"})
}
res.send("请求成功")
})

app.post('/usr/reg',(req,res)=>{
    let body =req.body
    
})


app.listen(3000,()=>{
    console.log('server start')
})