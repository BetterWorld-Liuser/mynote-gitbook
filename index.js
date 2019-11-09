var nodemailer = require('nodemailer')
const https = require('https')

https.get("https://www.baidu.com",(res)=>{
    let rawData = ""

    res.on("error",(err)=>{
        console.log(err)
    }
    )
    res.on("data",(chunk)=>{
        rawData+=chunk.toString('utf8')
        console.log("下载中....")
        //console.log(chunk.toString('utf8'))
    })
    res.on('end',()=>{
        console.log(rawData)
    })
})