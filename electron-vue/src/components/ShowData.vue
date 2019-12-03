<template>
    <div>
        <p @click="get_windows_name">{{this.gfname}}</p>
    </div>
</template>


<script>
//const { BrowserWindow } = require('electron').remote
import gfwiname from '../../node_modules/'


export default {
    name: 'ShowData',
  props: {
    msg: String
  },
  data(){
      return{
          gfname:'testString'
      }
  },
  method:{
      get_windows_name()
      {
          setTimeout(2000)
      }
  }
}
</script>


<style scoped>

</style>