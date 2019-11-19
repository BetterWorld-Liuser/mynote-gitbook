$(document).ready(function(){
    $("#logo-search").remove;
    $("#navigation").remove;
    
})





$(document).ready(function(){

    rmvclass = function(className){
        let div = document.getElementsByClassName(className)[0]
        let parent = div.parentNode
        parent.removeChild(div)
    }
    rmvId = function(Id){
        document.getElementById(Id).style.visibility="hidden"
    }
    let classNames = ["logo","navigation","fixed-btn","nav"]
    let Ids = ["pull"]
    
    
    classNames.forEach(rmvclass)
    Ids.forEach(rmvId) 


})