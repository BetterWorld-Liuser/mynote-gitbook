const express = require('express')
const bodyParser = require('body-parser')
const app = express()

//express不能直接解析post.body，这一步添加插件
app.use(bodyParser.urlencoded({extended:false}))
app.use(bodyParser.json())

app.use('/',(req,res,next)=>{
    console.log('中间件')
    let {token} = req
    if(token){
        next()    
    }else{
        res.send('缺少token')
    }
    
})



app.get('/user/login',(req,res)=>{
let query = req.query

if(query.us==='?'&&query.ps=='?'){
    res.send({"err":0,"msg":"login ok"})
    
}else{
    res.send({"err":-1,"msg":"login not ok"})
}
res.send("请求成功")
})

//middlewear.js
app.get('/test1',(req,res)=>{
let {token} = req.query

if(token){
    res.send("ok")
}else{
    res.send("no-ok")
}




})





app.post('/usr/reg',(req,res)=>{
    let body =req.body

})








app.listen(3000,()=>{
    console.log('server start')
})