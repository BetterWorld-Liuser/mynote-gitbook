<template>
  <div id="app" >
    <ShowData></ShowData>
  </div>
</template>

<script>
//import HelloWorld from './components/HelloWorld.vue'
import ShowData from './components/ShowData'

export default {
  name: 'app',
  components: {
    ShowData
  }
}
</script>

<style>
#app {
  height: 1100px;
  background-color: white;
  border-radius: 10px;
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  overflow: scroll;
}
</style>
