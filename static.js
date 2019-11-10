const express = require('express')
const path = require('path')
const app = express()


let pathName = "1234"
pathName = path.join(__dirname,'./kowledge_manager')
console.log(pathName)

app.use(express.static(pathName))


app.listen(3000,()=>{
    console.log('server start')
})