module Styles = {
  open Css;

  let container = style([textAlign(`initial)]);

  let title =
    style([
      fontSize(rem(2.)),
      color(rgb(34, 34, 34)),
      lineHeight(px(40)),
    ]);

  let role =
    style([
      fontSize(rem(1.3)),
      color(rgb(68, 68, 68)),
      lineHeight(px(26)),
      marginTop(px(8)),
      fontWeight(medium),
    ]);
};

[@react.component]
let make = (~profile: Data.profile) => {
  <div className=Styles.container>
    <div>
      <h1 className=Styles.title> {React.string(profile.name)} </h1>
      <p className=Styles.role> {React.string(profile.role)} </p>
      <About resume={profile.resume} />
    </div>
  </div>;
};