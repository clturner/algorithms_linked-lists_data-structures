#!/usr/bin/node

let myArgs = process.argv.slice(2);
let reqString = 'https://swapi.co/api/films/' + myArgs;

let request = require('request');
request(reqString, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    let obj = JSON.parse(body);
    for (let i = 0; i < obj.characters.length; i++) {
      reqString = obj.characters[i];
      request(reqString, function (error, response, body) {
        if (error) {
          console.log(error);
        } else {
          let nameObj = JSON.parse(body);
          console.log(nameObj.name);
        }
      });
    }
  }
});
