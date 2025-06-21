// // let a = 40;
// let b = 402

// try {
//   console.log(a);
// } catch {
//   console.log(b);
// }

let url = "https://catfact.ninja/fact";
//    normal way to use fetch
// fetch(url)
//   .then((res) => {
//      res.json().then((data)=>{
//         console.log(data.fact);
//      })

//   })
//   .catch((err) => {
//     console.log("eror-", err);
//   });

// fetch with async await
async function getFact() {
  let sol = await fetch(url);
   let data = sol.json();
   data.then((result) => {
     console.log(result)
   }).catch((err) => {
      console.log(err)
   });
  console.log("heelo");
}
