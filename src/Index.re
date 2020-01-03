type firebaseConfig = {
  apiKey: string,
  authDomain: string,
  databaseURL: string,
  projectId: string,
  storageBucket: string,
  messagingSenderId: string,
  appId: string,
  measurementId: string,
};

let options: firebaseConfig = {
  apiKey: "AIzaSyA9FXZSfWqnA2a3oQiKDdpVcyqtnm5fK10",
  authDomain: "litorsht.firebaseapp.com",
  databaseURL: "https://litorsht.firebaseio.com",
  projectId: "litorsht",
  storageBucket: "litorsht.appspot.com",
  messagingSenderId: "435093612673",
  appId: "1:435093612673:web:ae728305300a7ec8a04580",
  measurementId: "G-E06V413R2V",
};

[@bs.val]
external initializeApp: firebaseConfig => unit =
  "window.firebase.initializeApp";

initializeApp(options);

type doc = {id: string};
type collection = {
  add: string => Js.Promise.t(doc),
  get: unit => Js.Promise.t(array(doc)),
};

type db = {collection: string => collection};

[@bs.val] external firestore: unit => db = "window.firebase.firestore";

type data = {

  forEach: () => ()
}

[@bs.send] external collection: (db, string) => collection = "collection";
[@bs.send] external get: collection => Js.Promise.t(data) = "get";

let getAllParks = () =>
  /* let db = firestore(); */
  firestore()->collection("parks")->get
  |> Js.Promise.then_(value => {
       Js.log(value);
       Js.Promise.resolve(value);
     });

getAllParks();

/* var db = firebase.firestore(); */

ReactDOMRe.renderToElementWithId(
  <Component1 message="Hello! Click this text." />,
  "index1",
);

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");
