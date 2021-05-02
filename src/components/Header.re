module Styles = {
  open Css;

  let header =
    style([
      width(`percent(100.0)),
      height(px(146)),
      backgroundColor(rgb(17, 24, 39)),
      color(white),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
    ]);
  let bracket = style([color(rgb(204, 204, 204)), fontSize(rem(3.))]);

  let title = style([color(rgb(255, 255, 255)), fontSize(rem(3.))]);
};

module Bracket = {
  [@react.component]
  let make = (~text) => {
    <span className=Styles.bracket> {React.string(text)} </span>;
  };
};

[@react.component]
let make = () => {
  <header className=Styles.header>
    <Bracket text="<" />
    <h1 className=Styles.title> {"Bluuesz" |> React.string} </h1>
    <Bracket text="/>" />
  </header>;
};