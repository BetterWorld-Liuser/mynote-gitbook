const low = require('lowdb')
const fs = require('fs')
const Memery = require('lowdb/adapters/Memory')
const os = require('os')
const path = require('path')
const FileSync = require('lowdb/adapters/FileSync')
const adapter = new FileSync('../data/db.json')
const db = low(adapter)



let testContent = {
    target: "OneNote.exe",
    name: "测试添加新数据",
    key: "Ctrl + T"
}

let testData = {
    target: "OneNote.exe",
    name: "复制",
    order: 7,
    key: "Ctrl + C"
}

class DataHandler {

    /**
     * 初始化数据库
     */
    initData = function () {
        db.defaults({
            usrName: "",
            customize: true,
            database: [{
                appName: "OneNote.exe",
                ifExg:"flase",
                rank:1,
                keys: [
                    {
                        order: 2,
                        name: "复制",
                        key: "Ctrl + C"
                    },
                    {
                        order: 1,
                        name: "粘贴",
                        key: "Ctrl + V"
                    },
                    {
                        order: 3,
                        name: "粘贴",
                        key: "Ctrl + V"
                    }

                ]
            }]
        }).write()
    }



    /**
     * 对目标数据排序
    */
    sortData = function (appName) {

        //进行排序
        const result = db.get("database")
            .find({ 'appName': appName })
            .get("keys")
            .sortBy("order")
            .value()

        //将得到的排序写入json中    
        db.get("database")
            .find({ 'appName': appName })
            .get('keys')
            .assign(result)
            .write()

    }



    /**
     * 获得目标的json串等待进一步填充
     * @param {string} name - 比如OneNote
     * @returns {Object[]} result - 关于功能键的数组
     */
    getDataByName = function (name) {
        let result = db.get("database")
            .find({ "appName": name })
            .get("keys")
            .value()

        return result
    }

    /**
     *  将新的数据添加到列表最后 
     * content = {
     * target:"onenote",
     * name:"复制",
     * key:"Ctrl + C"
     * }
    */
    postData = function (content) {
        let target = db.get("database")
            .find({ "appName": content.target })
        if (target == {}) {
            db.get('database')
                .push({
                    "appName": content.target,
                    "keys": [
                        {
                            "order": 1,
                            "name": content.name,
                            "key": content.key
                        }
                    ]
                }).write()
        } else {
            target = target.get("keys")
        }

        let targetValue = target.value()

        //console.log(targetValue[2])
        let content_Value = {
            order: targetValue[targetValue.length - 1].order + 1,
            name: content.name,
            key: content.key
        }
        target.push(content_Value).write()
        //sortData(content.target)
    }


    /**
     * 修改某一数据后重新排序 
     */
    changeDataOrder = function (data) {
        let result = db.get("database")
            .find({ "appName": data.target })
            .get("keys")


        result.find({ name: data.name })
            .assign({ order: data.order, name: data.name, key: data.key })
            .write()

        sortData(data.target)
    }


    /**
     * 过滤重复的项目
     */
    deleteSameObject = function (name) {

        let array_chain = db.get('database')
            .find(
                { "appName": name }
            )


        let array = array_chain.get('keys').value()
        function charge(object, other) {
            if (object.name == other.name) {
                return true
            } else if (object.key == other.key) {
                return true
            } else {
                return false
            }
        }
        array_chain
            .set('keys', db._.uniqWith(array, charge))
            .write()
        return '过滤成功'
    }



}
//changeDataOrder(testData)

module.exports = DataHandler