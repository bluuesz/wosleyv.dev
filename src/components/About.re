module Styles = {
  open Css;

  let container = style([maxWidth(px(350)), marginTop(px(40))]);

  let title = style([fontSize(rem(1.5)), color(rgb(34, 34, 34))]);

  let about =
    style([
      marginTop(px(18)),
      fontSize(rem(1.)),
      width(`percent(100.)),
      wordBreak(`breakAll),
      color(rgb(51, 51, 51)),
    ]);
};

[@react.component]
let make = (~resume: Data.resume) => {
  <div className=Styles.container>
    <h1 className=Styles.title> {React.string("About me")} </h1>
    {resume
     |> List.mapi((i, p: Data.about) =>
          <p key={i |> string_of_int} className=Styles.about>
            {React.string(p.paragraph)}
          </p>
        )
     |> Array.of_list
     |> ReasonReact.array}
  </div>;
};