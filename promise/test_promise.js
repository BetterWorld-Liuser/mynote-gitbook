const fs = require('fs')

function isExit(){
    return new Promise((resolve,reject)=>{
        fs.stat('./hrhr',(err)=>{
            if(err){
                resolve('123')
            }else{
                reject('456')
            }
        })
    })
}