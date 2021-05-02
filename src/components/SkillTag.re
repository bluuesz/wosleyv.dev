module Styles = {
  open Css;

  let container =
    style([
      display(flexBox),
      alignItems(center),
      marginRight(px(15)),
      marginTop(px(25)),
    ]);
  let dot = bg =>
    style([
      height(px(22)),
      width(px(22)),
      backgroundColor(bg |> Data.color_of_tag),
      borderRadius(`percent(50.)),
      display(`inlineBlock),
    ]);

  let text = style([marginLeft(px(8))]);
};

[@react.component]
let make = (~tag: Data.tag) => {
  <div className=Styles.container>
    <span className={Styles.dot(tag)} />
    <p className=Styles.text> {tag |> Data.string_of_tag |> React.string} </p>
  </div>;
};