module Styles = {
  open Css;
  let box = bg =>
    style([
      padding(px(10)),
      width(`percent(100.)),
      /* background(
           linearGradient(
             `deg(90.),
             [
               (`percent(13.), rgb(231, 101, 101)),
               (`percent(52.), rgb(111, 5, 101)),
               (`percent(100.), rgb(1, 101, 101)),
             ],
           ),
         ), */
      background(bg |> Data.array_color_of_tag),
      color(white),
      borderRadius(px(5)),
      textAlign(center),
    ]);
};

[@react.component]
let make = (~skill: Data.skill) => {
  <div className={Styles.box(skill)}>
    <p> {skill.name |> React.string} </p>
  </div>;
};