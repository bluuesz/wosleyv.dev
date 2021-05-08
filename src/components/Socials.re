module Styles = {
  open Css;

  let socials =
    style([
      marginTop(px(22)),
      display(flexBox),
      justifyContent(center),
      selector("a + a", [marginLeft(px(20))]),
    ]);
};

[@react.component]
let make = () => {
  <div className=Styles.socials> <Github /> <Discord /> </div>;
};