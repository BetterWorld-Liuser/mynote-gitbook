const mongoose = require('mongoose')

mongoose.connect('mongodb://localhost/1902',{useNewUrlParser:true})


var db = mongoose.connection
db.on('error',console.error.bind(console,'connection error:'))
db.once('open',function(){
    console.log('ok')
})

let userSchema = new mongoose.Schema({
    us:{type:String,required:true},
    ps:{type:String,required:true},
    age:Number,
    sex:{type:Number,default:0},
})

let user = mongoose.model('user',userSchema)

user.insertMany([{
    
}])
