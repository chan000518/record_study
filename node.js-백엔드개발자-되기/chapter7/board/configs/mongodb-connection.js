const { MongoClient } = require("mongodb");
const uri =
    "mongodb+srv://wkdvnddl050701:Chan0518*@cluster0.wfs9xv3.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"
    
module.exports = function (callback) {
  return MongoClient.connect(uri, callback);
};