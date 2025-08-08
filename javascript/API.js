let url = "http://universities.hipolabs.com/search?name=";
// select the button to see the event           
let btn = document.querySelector("button");              

//  lets create  addEventListener
btn.addEventListener("click", async () => {
  let country = document.querySelector("input").value;
  // console.log(country);
  let result = await getcollage(country);
  // Show(result);
});

async function getcollage(country) {
  let res = await axios.get(url + country);

 try {
  let response = await axios.get(url+country);
   console.log(response)
 } catch (error) {
  console.log("error",error);
 }
}

 function show(it){
  let list = document.querySelector("#list");
  if(it &&  it.length>0){
    for(let col of it){
      let li = document.createElement("li");
            li.innerText = col.name;
            list.appendChild(li);
    }
  }else{
    list.innerText = "No universities found."; 
  }
 }

// create a function
// btn.addEventListener("click", async () => {
//   let country = document.querySelector("input").value; // Getting the country from the input
//   console.log(country);
//   let itr = await getcollage(country); // Get the colleges based on the country
//   show(itr); // Pass the data to the show function
// });

// function show(itr) {
//   let list = document.querySelector("#list");
//   list.innerText = ""; // Clear the existing list
//   if (itr && itr.length > 0) {
//     for (let col of itr) {
//       console.log(col.name);

//       let li = document.createElement("li");
//       li.innerText = col.name;
//       list.appendChild(li);
//     }
//   } else {
//     list.innerText = "No universities found.";
//   }
// }

//   //  first method using fect method  to acces the data comes from the url
// async function getcollage(country) {
//   try {
//     let response = await axios.get(url + country);
//     // console.log(response.data);
//     return response.data;
//   } catch (error) {
//     console.log("error-".error);
//   }
// }
