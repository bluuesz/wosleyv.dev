[@react.component]
let make = (~children) => {
  <h1> {children |> React.string} </h1>;
};